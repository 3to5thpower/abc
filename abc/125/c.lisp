(eval-when (:compile-toplevel :load-toplevel :execute)
  (defparameter OPT
    #+swank '(optimize (speed 3) (safety 2))
    #-swank '(optimize (speed 3) (safety 0) (debug 0))))

(defun main ()
  (let* ((n (read))
         (a (make-array n :element-type 'uint7)))
    (dotimes (i n) (setf (aref a i) (read)))
    (loop for i below n
       maximize
         (reduce (lambda (x y)
                   (unless (or (= x i) (= y i))
                     ) (a))))

#-swank(main))


