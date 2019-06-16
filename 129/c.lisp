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

;;本体
(defconstant *mod* 1000000007)

(defun main ()
  (let* ((n (read)) (m (read)) (ans 1)
         (fib (make-array (1+ n) :initial-element 1)))
    (loop for i from 2 to n
       do (vref fib i (+ (vref fib (- i 1))
                         (vref fib (- i 2)))))
    (dotimes (i n) (println (vref fib i)))
    (do* ((i 0 (1+ i))
          (pos 0 (+ 2 next))
          (next (1- (read)) (1- (read))))
        (())
      (if (= (- next (- pos 2)) 1)
          (setf ans 0)
          (setf ans (mod (* ans (vref fib (- next pos))) *mod*)))
      (if (= i (1- m))
          (progn
            (setf ans (mod (* ans (vref fib (- n pos))) *mod*))
            (return))))
    (println ans)))


#-swank(main)
