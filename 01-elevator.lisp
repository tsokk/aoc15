(with-open-file (my-stream "input/1.txt" :direction :input)
  (let ((input (read-line my-stream)))
    (reduce #'+
	    (map 'list (lambda (c)
			 (if (eql c #\()
			     1
			     -1))
		 input))))
					; => 138

(with-open-file (my-stream "input/1.txt" :direction :input)
  (let* ((input (read-line my-stream))
	 (numbers (map 'list (lambda (c)
			       (if (eql c #\()
				   1
				   -1))
		       input))
	 (cum-sum (loop for n in numbers
			sum n into ans
			collect ans)))
    (labels ((rec (lst idx)
	       (cond ((null (car lst)) idx)
		     ((= (car lst) -1) idx)
		     (t (rec (cdr lst) (1+ idx))))))
      (rec cum-sum 1))))
					; => 1771
