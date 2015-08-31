 (deftemplate print (slot value))
 
 (deffacts initial
 (print (value true)))
 
 (defrule canPrint
 (print (value true) )
 =>
(printout decision "")
	  (readline))
