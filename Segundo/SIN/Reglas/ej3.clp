
;4.- Haz un programa que detecte e imprima los hechos 
;   (vector <nombreVector> ...) que contengan los 
;    valores 3 y 4 en alguna posición, y que entre éstos 
;    haya un numero impar de valores. Se debe utilizar la 
;    función length$ (ver documentación).
;    ver https://www.csie.ntu.edu.tw/~sylee/courses/clips/rhs.htm

(deffacts hechos
  (datos 2 1 23 1)
  (datos 1 34 nuevo 6)
  (datos 5 34 1 6)
  (datos 6 34 23 32 13)
  (datos 2 1 23 78 5)
)

(defrule TresCuatro
    ?hechoResult <- (or (vector $?Antes 3 $?Medio&:(oddp (length$ $?Medio)) 4 $?Final)
                         (vector $?Antes 4 $?Medio&:(oddp (length$ $?Medio)) 3 $?Final))
    =>
    (printout t ?hechoResult crlf)
)
