--Ejercicio 1
SELECT v.nombrecompleto FROM votantes v, localidades l 
    WHERE (SUBSTR(v.dni,8,8) - 1 = l.idlocalidad) and (l.idlocalidad = v.localidad);

--Ejercicio 2
SELECT v.nombrecompleto, DECODE(l.provincia, 1, "Madrid", l.nombre) as ciudad
    FROM vontantes v, localidades l
    WHERE v.localidad = l.idlocalidad;

--Ejecicio 3
SELECT p.siglas FROM partidos p, eventos_resultados e
  WHERE COUNT(e.partido) > (SELECT partido, COUNT(partido) FROM eventos_resultados GROUP BY partido)
    GROUP BY p.siglas;

