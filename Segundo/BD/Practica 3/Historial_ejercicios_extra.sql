--Ejercicio 1
SELECT CONCAT(CONCAT(l.nombre, ' va antes que '), lc.nombre) FROM localidades l, localidades lc
WHERE l.idlocalidad + 1 = lc.idlocalidad
ORDER BY l.idlocalidad;

--Ejercicio 2
SELECT nombre FROM localidades
  WHERE numerohabitantes > (
    SELECT numerohabitantes FROM localidades
      WHERE idlocalidad = (
      SELECT localidad FROM votantes
        WHERE fechanacimiento = (
          SELECT MIN(fechanacimiento) FROM votantes
            WHERE fechanacimiento > (
              SELECT MIN(fechanacimiento) from votantes))));