CREATE Table prueba
	(
	 edad Number(2,0),
	 nombre varchar2(40)
	);

INSERT INTO prueba
	VALUES (23, 'Perez Perez, Jose');

INSERT INTO prueba
	VALUES (19, 'Marquez Doblas, Jose');

INSERT INTO prueba
	VALUES (19, 'Luque Leon, Alejandro');

SELECT * FROM prueba;

SELECT * FROM prueba WHERE edad=23;

UPDATE prueba SET edad=46 WHERE edad=23;

DELETE FROM prueba;

DROP Table prueba;

DESCRIBE votantes;




