(eval-when (:compile-toplevel :load-toplevel :execute)
  (defparameter OPT
    #+swank '(optimize (speed 3) (safety 2))
    #-swank '(optimize (speed 3) (safety 0) (debug 0)))
  #+swank (progn (ql:quickload '(:cl-debug-print))))
#+swank (cl-syntax:use-syntax cl-debug-print:debug-print-syntax)

(deftype int32 () '(signed-byte 32))
(deftype int64 () '(signed-byte 64))


;;macros
(defmacro rep (i n &body body)
  `(dotimes (,i ,n) ,@body))

(defmacro rep1 (i s g &body body)
  `(loop for ,i from ,s below ,g
      do ,@body))

;;vector
(defmacro vec (type &optional (num 0) (val 0))
  (let* ((g (gensym)))
    `(let* ((,g ,num)
            (dim (if (> ,g 100) (+ ,g 100) 100)))
       (make-array dim :element-type ',type :initial-element ,val
                   :adjustable t :fill-pointer ,g))))

(defmacro vint (&optional (num 0) (val 0))
  `(vec int32 ,num ,val))

(defmacro vref (vector pos &optional value)
  (let ((g (gensym)))
    `(let ((,g ,value))
       (if ,g
           (setf (aref ,vector ,pos) ,g)
           (aref ,vector ,pos)))))

(defun chmax (var comp &optional (predicate #'>))
  (if (or (null var) (not (funcall predicate var comp)))
        (setf var comp)))
(defun chmin (var comp &optional (predicate #'<))
  (if (or (null var) (not (funcall predicate var comp)))
        (setf var comp)))



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


(defun main ()
  (let* ((n (read))
         ma mi)
    (dotimes (i n)
      (let ((temp (read)))
        (chmax ma temp)
        (chmin mi temp)))
    (princ (- ma mi))
    (terpri)))
 
#-swank(main)
