; Recibe 4 números y devuelve la diferencia entre el máximo y el mínimo
(deffunction pruebaClase
    (?a ?b ?c ?d)
    (if (or (or(not (integerp ?a)) (not (integerp ?b))) (or (not (integerp ?c)) (not (integerp ?d))))
        then 
            (printout t "Factorial Error!" crlf)
        else
            (printout t (- (max ?a ?b ?c ?d) (min ?a ?b ?c ?d))  crlf)
    )
)