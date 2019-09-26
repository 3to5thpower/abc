(eval-when (:compile-toplevel :load-toplevel :execute)
  (defparameter OPT
    #+swank '(optimize (speed 3) (safety 2))
    #-swank '(optimize (speed 3) (safety 0) (debug 0)))
  #+swank (progn (ql:quickload '(:cl-debug-print))))
#+swank (cl-syntax:use-syntax cl-debug-print:debug-print-syntax)

(deftype int32 () '(signed-byte 32))
(deftype int64 () '(signed-byte 64))


;;macros
(defmacro println (n)
  `(format t "~a~%" ,n))
(defmacro vint-out (vec)
  `(progn
     (rep i (length ,vec)
          (princ (vref ,vec i))
          (princ " "))
     (fresh-line)))
(defmacro aif (test-form then-form &optional else-form)
  `(let ((it ,test-form))
     (if it ,then-form ,else-form)))

;;vector
(defmacro vec (type &optional (num 100) (val 0))
  (let* ((g (gensym)))
    `(let* ((,g ,num))
       (make-array ,g :element-type ',type :initial-element ,val
                   :adjustable nil :fill-pointer ,g))))

(defmacro double-vec (type &optional (dim1 100) (dim2 100) (val 0))
  `(make-array '(,dim1 ,dim2) :element-type ',type :initial-element ,val))

(defmacro vint (&optional (num 0) (val 0))
  `(vec int32 ,num ,val))

(defmacro double-vec (type &optional (dim1 100) (dim2 100) (val 0))
  `(make-array '(,dim1 ,dim2) :element-type ',type :initial-element ,val))

(defmacro vref (vector pos &optional value)
  (let ((g (gensym)))
    `(let ((,g ,value))
       (if ,g
           (setf (aref ,vector ,pos) ,g)
           (aref ,vector ,pos)))))

(defmacro chvar (sym comp predicate)
  (let ((g (gensym)))
    `(let ((,g ,comp))
       (if (or (null ,sym) (not (funcall ,predicate ,sym ,g)))
           (setf ,sym ,g)))))

(defmacro chmax (sym comp &optional (predicate #'>))
  `(chvar ,sym ,comp ,predicate))

(defmacro chmin (sym comp &optional (predicate #'<))
  `(chvar ,sym ,comp ,predicate))

(defmacro defchangef (name op default-val)
  `(defmacro ,name (var &optional (val ,default-val))
     `(setq ,var (,',op ,val ,var))))
(defmacro read-str ()
  `(write-to-string (read)))
(defmacro print-float (r)
  `(format t "~,9F~%" (coerce ,r 'double-float)))


;;本体
(defun main ()
  (let* ((a (read)) (b (read))
         (c (read)) (d (read)) (e (* c d)) (cc c) (dd d) (ee e))
    (loop while (< cc a) do (incf cc c)
       finally (incf cc c))
    (loop while (< dd a) do (incf dd d)
       finally (incf dd d))
    (loop while (< ee a) do (incf ee e)
       finally (incf ee e))
    (println
     (+ (- (1+ (- b a))
           (loop for i from cc by c
              while (<= i b) count i)
           (loop for i from dd by d
              while (<= i b) count i))
        (loop for i from ee by e
             while (<= i b) count i)))))

#-swank(main)
