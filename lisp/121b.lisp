(setq n (read))
(setq m (read))
(setq c (read))
(setq b 
      (loop for i below m
            collect(read)))
(setq ans 0)
(loop for i below n
  (if (plusp
       (apply #'+
              (mapcar #'+
                      (loop for a below m collect (read))
                       b)))
      (incf ans))))
(princ ans)
