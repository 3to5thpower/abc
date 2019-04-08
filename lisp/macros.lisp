(defmacro rep(i n &body body)
  `(loop for ,i from 0 below ,n
      do,@body))

(defmacro vint(name)
  `(defparameter ,name
       (make-array 100 :element-type 'integer
               :adjustable t
               :fill-pointer 0)))
(defun push_back (vec n)
  (vector-push-extend n vec))
