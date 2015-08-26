 (deftemplate print (slot value))
 
 (deffacts initial
 (print (value true)))
 
 (defrule canPrint
 (print (value true) )
 =>
(printout decision "0/476;186")
	  (readline))
