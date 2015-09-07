(do-for-all-facts ((?f unit)) (and(<> ?f:isAlive 0)  (eq ?f:type knight))(printout t ?f:id crlf)
(modify 1 (selectedUnitIndex 1) (selectedFieldIndex 5)))