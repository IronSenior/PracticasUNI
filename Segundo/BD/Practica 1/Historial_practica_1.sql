--Muestra todas las columnas de la tabl partidos
SELECT * FROM partidos;

--Para mostrar solo algunas columnas de la tabla partidos
SELECT idpartido, siglas, presidente FROM partidos;

--Muestra la columna siglas de la tabla partidos pero con el titulo de "Siglas de partido"
SELECT siglas "Siglas de partido" FROM partidos;

--Muestra datos de dos tablas en los que los atributos tienen el mismo nombre
SELECT
  localidades.nombre, localidades.numeroHabitantes, provincias.nombre, provincias.numeroHabitantes
FROM
  localidades, provincias;

--Lo mismo que antes pero con alias en las tablas
SELECT
  l.nombre, l.numeroHabitantes, p.nombre, p.numeroHabitantes
FROM
  localidades l, provincias p;

--Muestra información sobre la tabla
DESCRIBE partidos;

--Insertamos los valores de Maria
INSERT INTO votantes VALUES 
(30653845,'Maria Gonzalez Ramirez', 'Doctorado', 'Activo', 'goram@telefonica.es', 1, '21/08/1989', 677544822);

--Comprobamos que los hemos metido bien
SELECT * FROM votantes;

--Los borramos
DELETE FROM votantes WHERE dni=30653845;

-- Sacamos solo el nombre, el tipo y la fecha de los eventos
SELECT nombre, tipo, fecha FROM eventos;

-- || sirve para concatenar textos
SELECT nombre||' de tipo '||tipo as "Convocatoria" FROM eventos;
