(eval-when (:compile-toplevel :load-toplevel :execute)
  (defparameter OPT
    #+swank '(optimize (speed 3) (safety 2))
    #-swank '(optimize (speed 3) (safety 0) (debug 0)))
  #+swank (progn (ql:quickload '(:cl-debug-print))))
#+swank (cl-syntax:use-syntax cl-debug-print:debug-print-syntax)

(deftype int32 () '(signed-byte 32))
(deftype int64 () '(signed-byte 64))
(deftype int7 () '(signed-byte 7))

;;macros
(defmacro println (n)
  `(format t "~a~%" ,n))
(defmacro vint-out (vec)
  `(progn
     (rep i (length ,vec)
          (princ (vref ,vec i))
          (princ " "))
     (fresh-line)))


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


;;本体
(defvar n (read))
(defvar a (make-array `(2 ,n) :element-type 'int7))
(dotimes (i 2)
  (dotimes (j n)
    (setf (aref a i j) (read))))

(defun dfs (i j arr)
  (cond ((and (= i 1) (= j (1- n))) (aref arr 1 (1- n)))
        ((= i 1) (+ (dfs i (1+ j) arr) (aref arr i j)))
        ((= j (1- n)) (+ (dfs 1 j arr ) (aref arr i j)))
        (t (max (+ (dfs i (1+ j) arr) (aref arr i j))
                (+ (dfs (1+ i) j arr) (aref arr i j))))))

(defun main ()
  (println (dfs 0 0 a)))

  
#-swank(main)
