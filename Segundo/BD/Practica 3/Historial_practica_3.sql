--Ejercicio 1
SELECT v.nombrecompleto FROM votantes v, localidades l 
    WHERE (SUBSTR(v.dni,8,8) - 1 = l.idlocalidad) and (l.idlocalidad = v.localidad);

--Ejercicio 2
SELECT v.nombrecompleto, DECODE(l.provincia, 1, "Madrid", l.nombre) as ciudad
    FROM vontantes v, localidades l
    WHERE v.localidad = l.idlocalidad;

--Ejecicio 3
SELECT p.siglas FROM partidos p, eventos_resultados e 
  WHERE p.idpartido = e.partido
  HAVING COUNT(e.partido) = (SELECT MAX(COUNT(partido)) FROM eventos_resultados GROUP BY partido)
  GROUP BY p.siglas;

--Ejercicio 4
SELECT dni FROM votantes
  WHERE fechanacimiento = ( SELECT MIN(fechanacimiento) FROM votantes 
                              WHERE fechanacimiento > (SELECT MIN(fechanacimiento) FROM votantes));

--Ejercicio 5
SELECT v.dni, COUNT(c.votante) FROM votantes v, consultas c
  WHERE c.votante = v.dni
  GROUP BY v.dni
  ORDER BY COUNT(c.votante) DESC;

--Ejercicio 6
SELECT v.dni, COUNT(c.votante) FROM votantes v, consultas c
  WHERE c.votante = v.dni
  GROUP BY v.dni
  HAVING COUNT(c.votante) > ((SELECT COUNT(c.votante) FROM consultas c)/(SELECT COUNT(dni) FROM votantes))
  ORDER BY COUNT(c.votante) DESC;

--Ejercicio 7
SELECT v.nombrecompleto FROM votantes v, consultas c
  WHERE c.votante = v.dni
  GROUP BY v.nombrecompleto
  HAVING COUNT(c.votante) > ((SELECT COUNT(c.votante) FROM consultas c)/(SELECT COUNT(dni) FROM votantes));

--Ejercicio 8
SELECT v.dni, COUNT(c.votante) FROM votantes v, consultas c
  WHERE c.votante = v.dni and v.dni != (SELECT dni FROM votantes
                                            WHERE fechanacimiento = ( SELECT MIN(fechanacimiento) FROM votantes 
                                                                        WHERE fechanacimiento > (SELECT MIN(fechanacimiento) FROM votantes)))
  GROUP BY v.dni
  ORDER BY COUNT(c.votante) DESC;