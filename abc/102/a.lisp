(let ((n (read)))
  (princ
   (if (evenp n)
       n
       (* n 2))))
(format t "~%")
