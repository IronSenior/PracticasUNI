;===================================================================
;3.- Haz un programa que dado un único hecho datos con un número 
;    indefinido de valores (ejemplo: (datos hola 1 3 nuevo 1 adios)), 
;    elimine todas las apariciones del valor 1.

(deffacts hechos
  (datos 2 1 23 1)
  (datos 1 34 nuevo 6)
  (datos 5 34 1 6)
  (datos 6 34 23 32 13)
  (datos 2 1 23 78 5)
)

;Mi solución
(defrule ElimineUnos
  ?hechoResult <- (datos $?Antes 1 $?Despues)
    =>
  (retract ?hechoResult)
  (assert (datos $?Antes $?Despues)
)