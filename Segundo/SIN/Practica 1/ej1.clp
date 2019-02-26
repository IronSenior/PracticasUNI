(deffacts h1
	(dato 3)
	(dato 6)
	(dato 9)
)

(defrule r1
	(dato ?x); Antecendente
	
	=>
	
	(assert (resultado (* 2 ?x)))
)
