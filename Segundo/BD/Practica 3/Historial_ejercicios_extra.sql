--Ejercicio 1
SELECT CONCAT(CONCAT(l.nombre, ' va antes que '), lc.nombre) FROM localidades l, localidades lc
WHERE l.idlocalidad + 1 = lc.idlocalidad
ORDER BY l.idlocalidad;