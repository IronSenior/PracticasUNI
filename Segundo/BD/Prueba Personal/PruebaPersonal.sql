--Ejercicio 1
SELECT l.nombre, l.numerohabitantes FROM localidades l
  WHERE idlocalidad = (
    SELECT v.localidad FROM votantes v
        WHERE fechanacimiento = (
          SELECT MAX(v.fechanacimiento) FROM votantes v));

--Ejercicio 2
SELECT v.nombrecompleto, v.fechanacimiento FROM votantes v, provincias p, localidades l 
  WHERE fechanacimiento > (SELECT fechacreacion FROM partidos WHERE siglas = 'PP')
    AND l.idlocalidad = v.localidad
    AND l.provincia = p.idprovincia
    AND p.comunidad = 'Andalucia'
    ORDER BY fechanacimiento ASC;

--Ejercicio 3
SELECT l.nombre, p.comunidad FROM localidades l, provincias p
WHERE l.numerohabitantes > (
  SELECT numerohabitantes FROM localidades
    WHERE idlocalidad = (
      SELECT localidad FROM votantes
        WHERE fechanacimiento = (
          SELECT MIN(fechanacimiento) FROM votantes
            WHERE fechanacimiento > (SELECT MIN(fechanacimiento) FROM votantes))))
  AND l.provincia = p.idprovincia
  ORDER BY l.nombre;