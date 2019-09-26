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


(defmacro rep (i n &body body)
  `(dotimes (,i ,n) ,@body))

(defmacro rep1 (i s g &body body)
  `(loop for ,i from ,s below ,g
      do ,@body))

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

;;本体

(defun ctoi (c)
  (- (char-int c) (char-int #\0)))

(defun main()
  (let ((n-str (read-line)) (n 0) sn)
    (setf sn (reduce #'+ (map 'vector #'ctoi n-str)))
    (dotimes (i (length n-str))
         (setf n (+ n (* (ctoi (aref (reverse n-str) i)) (expt 10 i)))))
    (if (zerop (mod n sn))
        (println "Yes")
        (println "No"))))



#-swank(main)

