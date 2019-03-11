;1.- Haz un programa que dado un conjunto de hechos de tipo datos 
;    con un número indefinido de valores, detecte e imprima 
;    aquellos tal que el primer valor sea par y menor o igual 
;    al último.

(deffacts hechos
  (datos 2 34 23 1)
  (datos 4 34 23 6)
  (datos 5 34 23 6)
  (datos 6 34 23 32 13)
  (datos 2 34 23 78 5)
  
)

;Solución del profesor
(defrule regla 
?dh<-	(datos ?x&:(numberp ?x)&:(evenp ?x) $? ?y&:(<= ?x ?y)) 
	=> 
	(printout t ?dh "   " ?x crlf)
)


;Mi solución (La misma pero documentada)
; 
(defrule paresYmenores
;En hechoResult se guardará la dirección del hecho que cumpla las condiciones
;Un hecho de tipo datos cuyo primer elemento x sea un numero y numero par, y su ultimo elemento sea menor que x
?hechoResult <- (datos ?x&:(numberp ?x)&:(evenp ?x) $? ?y&:(numberp ?y)&:(<= ?x ?y))
  =>
  (printout t ?hechoResult "     " ?x crlf)
)
