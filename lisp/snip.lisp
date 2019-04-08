(eval-when (:compile-toplevel :load-toplevel :execute)
  (defparameter OPT
    #+swank '(optimize (speed 3) (safety 2))
    #-swank '(optimize (speed 3) (safety 0) (debug 0)))
  #+swank (progn (ql:quickload '(:cl-debug-print :fiveam))
                 (shadow :run)
                 (use-package :fiveam)))
#+swank (cl-syntax:use-syntax cl-debug-print:debug-print-syntax)
 
;; BEGIN_INSERTED_CONTENTS
#+sbcl
(eval-when (:compile-toplevel :load-toplevel :execute)
  (sb-c:defknown init-vector (vector)
      vector (sb-c:flushable)
    :overwrite-fndb-silently t)
 
  (sb-c:defoptimizer (init-vector sb-c:derive-type) ((template))
    (let* ((template-type (sb-c::lvar-type template))
           (spec `(,(if (sb-kernel:array-type-complexp template-type) 'array 'simple-array)
                   ,(sb-kernel:type-specifier (sb-kernel:array-type-element-type template-type))
                   (*))))
      (sb-c::careful-specifier-type spec))))
 
(defun init-vector (template)
  "Returns a newly initialized vector of the same type as TEMPLATE vector with
SIZE."
  (declare (optimize (speed 3)))
  (make-array (length template) :element-type (array-element-type template)))
 
(declaim (inline %merge))
(defun %merge (l mid r source-vec dest-vec predicate key)
  (declare ((mod #.array-total-size-limit) l mid r)
           (function predicate key))
  (loop with i = l
        with j = mid
        for idx from l
        when (= i mid)
        do (loop for j from j below r
                 for idx from idx
                 do (setf (aref dest-vec idx)
                          (aref source-vec j))
                 finally (return-from %merge t))
        when (= j r)
        do (loop for i from i below mid
                 for idx from idx
                 do (setf (aref dest-vec idx)
                          (aref source-vec i))
                 finally (return-from %merge t))
        do (if (funcall predicate
                        (funcall key (aref source-vec i))
                        (funcall key (aref source-vec j)))
               (setf (aref dest-vec idx) (aref source-vec i)
                     i (1+ i))
               (setf (aref dest-vec idx) (aref source-vec j)
                     j (1+ j)))))
 
(declaim (inline %insertion-sort!))
(defun %insertion-sort! (vec predicate l r key)
  (declare (function predicate key)
           ((mod #.array-total-size-limit) l r))
  (loop for end from (+ l 1) below r
        do (loop for i from end above l
                 while (funcall predicate
                                (funcall key (aref vec i))
                                (funcall key (aref vec (- i 1))))
                 do (rotatef (aref vec (- i 1)) (aref vec i)))
        finally (return vec)))
 
(declaim (inline merge-sort!))
(defun merge-sort! (vector predicate &key (start 0) end (key #'identity))
  (declare (vector vector)
           (function predicate key))
  (let ((end (or end (length vector))))
    (declare ((mod #.array-total-size-limit) start end))
    (let ((buffer (init-vector vector)))
      (symbol-macrolet ((vec1 vector) (vec2 buffer))
        (labels ((recurse (l r merge-to-vec1-p)
                   (declare (optimize (safety 0))
                            ((mod #.array-total-size-limit) l r))
                   (cond ((= l r))
                         ((and (<= (- r l) 32) merge-to-vec1-p)
                          (%insertion-sort! vec1 predicate l r key))
                         ;; ((= (+ l 1) r)
                         ;;  (unless merge-to-vec1-p
                         ;;    (setf (aref vec2 l) (aref vec1 l))))
                         ;; ((= (+ l 2) r)
                         ;;  ;; I put this clause just for efficiency.
                         ;;  (if (funcall predicate
                         ;;               (funcall key (aref vec1 l))
                         ;;               (funcall key (aref vec1 (- r 1))))
                         ;;      (unless merge-to-vec1-p
                         ;;        (setf (aref vec2 l) (aref vec1 l)
                         ;;              (aref vec2 (- r 1)) (aref vec1 (- r 1))))
                         ;;      (if merge-to-vec1-p
                         ;;          (rotatef (aref vec1 l) (aref vec1 (- r 1)))
                         ;;          (setf (aref vec2 l) (aref vec1 (- r 1))
                         ;;                (aref vec2 (- r 1)) (aref vec1 l)))))
                         (t (let ((mid (floor (+ l r) 2)))
                              (recurse l mid (not merge-to-vec1-p))
                              (recurse mid r (not merge-to-vec1-p))
                              (if merge-to-vec1-p
                                  (%merge l mid r vec2 vec1 predicate key)
                                  (%merge l mid r vec1 vec2 predicate key)))))))
          (recurse start end t)
          vector)))))
 
(defmacro with-output-buffer (&body body)
  "Buffers all outputs to *STANDARD-OUTPUT* and flushes them to
*STANDARD-OUTPUT* at the end. Note that only BASE-CHAR is allowed."
  (let ((out (gensym)))
    `(let ((,out (make-string-output-stream :element-type 'base-char)))
       (let ((*standard-output* ,out))
         ,@body)
       (write-string (get-output-stream-string ,out)))))
 
(declaim (ftype (function * (values fixnum &optional)) read-fixnum))
(defun read-fixnum (&optional (in *standard-input*))
  (declare #.OPT)
  (macrolet ((%read-byte ()
               `(the (unsigned-byte 8)
                     #+swank (char-code (read-char in nil #\Nul))
                     #-swank (sb-impl::ansi-stream-read-byte in nil #.(char-code #\Nul) nil))))
    (let* ((minus nil)
           (result (loop (let ((byte (%read-byte)))
                           (cond ((<= 48 byte 57)
                                  (return (- byte 48)))
                                 ((zerop byte) ; #\Nul
                                  ;; (return-from read-fixnum 0)
                                  (error "Read EOF or #\Nul."))
                                 ((= byte #.(char-code #\-))
                                  (setf minus t)))))))
      (declare ((integer 0 #.most-positive-fixnum) result))
      (loop
        (let* ((byte (%read-byte)))
          (if (<= 48 byte 57)
              (setq result (+ (- byte 48) (the fixnum (* result 10))))
              (return (if minus (- result) result))))))))
 
(defmacro dbg (&rest forms)
  #+swank
  (if (= (length forms) 1)
      `(format *error-output* "~A => ~A~%" ',(car forms) ,(car forms))
      `(format *error-output* "~A => ~A~%" ',forms `(,,@forms)))
  #-swank (declare (ignore forms)))
 
(defmacro define-int-types (&rest bits)
  `(progn
     ,@(mapcar (lambda (b) `(deftype ,(intern (format nil "UINT~A" b)) () '(unsigned-byte ,b))) bits)
     ,@(mapcar (lambda (b) `(deftype ,(intern (format nil "INT~A" b)) () '(signed-byte ,b))) bits)))
(define-int-types 2 4 7 8 15 16 31 32 62 63 64)
 
(defmacro println (obj &optional (stream '*standard-output*))
  `(let ((*read-default-float-format* 'double-float))
     (prog1 (princ ,obj ,stream) (terpri ,stream))))
 
(defconstant +mod+ 1000000007)
 
;; Body
 
(defun main ()
  (declare #.OPT
           (inline sort))
  (let* ((x (read))
         (y (read))
         (z (read))
         (k (read))
         (as (make-array x :element-type 'uint62 :initial-element 0))
         (bs (make-array y :element-type 'uint62 :initial-element 0))
         (cs (make-array z :element-type 'uint62 :initial-element 0))
         (abs (make-array (* x y) :element-type 'uint62))
         (abcs (make-array (* k z) :element-type 'uint62)))
    (declare (uint16 x y z k))
    (dotimes (i x) (setf (aref as i) (read-fixnum)))
    (dotimes (i y) (setf (aref bs i) (read-fixnum)))
    (dotimes (i z) (setf (aref cs i) (read-fixnum)))
    (let ((index 0))
      (dotimes (i x)
        (dotimes (j y)
          (setf (aref abs index) (+ (aref as i) (aref bs j)))
          (incf index))))
    (merge-sort! abs #'>)
    (let ((index 0))
      (dotimes (i (min k (* x y)))
        (dotimes (j z)
          (setf (aref abcs index) (+ (aref abs i) (aref cs j)))
          (incf index))))
    (merge-sort! abcs #'>)
    (with-output-buffer
      (dotimes (i k)
        (println (aref abcs i))))))
 
#-swank(main)
