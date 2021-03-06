-- Ejercicio 1 
SELECT * FROM votantes WHERE nombrecompleto LIKE '%n';

--Ejercicio 2
SELECT * FROM votantes WHERE dni LIKE '%5%5%5%';

--Ejercicio 3
SELECT * FROM votantes WHERE fechanacimiento > '01/01/90';

--Ejercicio 4
SELECT v.nombrecompleto, l.nombre FROM votantes v, localidades l WHERE v.localidad = l.idlocalidad and l.numerohabitantes > 300000;

--Ejercicio 5
SELECT v.nombrecompleto, p.comunidad FROM votantes v, provincias p, localidades l 
  WHERE v.localidad = l.idlocalidad and l.provincia = p.idprovincia and l.numerohabitantes > 300000;

--Ejercicio 6
SELECT partido, COUNT(partido) FROM consultas_datos group by partido;

--Ejercicio 7
SELECT partido, COUNT(consulta) FROM consultas_datos group by partido;

--Ejercicio 8
SELECT p.nombrecompleto FROM consultas_datos c, partidos p
    WHERE c.partido = p.idpartido
    GROUP BY p.nombrecompleto
    HAVING COUNT(c.consulta) > 10;

--Ejercicio 9
SELECT p.nombrecompleto, COUNT(c.consulta) as "conteo" FROM consultas_datos c, partidos p
    WHERE c.partido = p.idpartido
    GROUP BY p.nombrecompleto
    HAVING COUNT(c.consulta) > 10;

--Ejercicio 10 (Me salen numeros distintos a la solucion)
SELECT p.nombrecompleto, COUNT(c.consulta) as "Conteo" FROM consultas_datos c, partidos p
    WHERE c.partido = p.idpartido and c.certidumbre > 0.8 and c.respuesta = 'Si'
    GROUP BY p.nombrecompleto;