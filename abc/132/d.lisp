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
(defmacro read-str () ;readを使う都合上0000などは文字列として読み込むことができない
  `(write-to-string (read)))
(defmacro print-float (r)
  `(format t "~,9F~%" (coerce ,r 'double-float)))
(defmacro tlet (bindings &body body)
  `(let (,@(mapcar (lambda (binding)
                     (subseq binding 0 2))
                   bindings))
     (declare ,@(mapcar (lambda (binding)
                          (list 'type (caddr binding) (car binding)))
                        bindings))
     ,@body))

;;本体
(define-symbol-macro *mod* (+ 7 (expt 10 9)))

(defvar fact (vec integer 2000 1))
(loop for i from 1 below 2000
   do (vref fact i (* i (vref fact (1- i)))))

(defmacro product (start end)
  `(do ((i ,start (1+ i))
       (res 1))
      ((= i ,end) res)
    (setq res (* res i))))

(defun div (n r)
  (mod (/ (vref fact (+ n r -1))
          (vref fact n)
          (vref fact (1- r)))
       *mod*))

(defun main()
  (let ((n (read)) (k (read)))
    (dotimes (i k)
      (println
       (mod (* (div (- k i 1) (1+ i))
               (div (- n k i) (+ i 2)))
            *mod*)))))

#-swank(main)



