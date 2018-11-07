--Primero inicio el servidor de output
set serveroutput on;
--Comienzan mis bloques de codgio
DECLARE
  mydni NUMBER := 30983712;
  votante votantes%rowtype;
BEGIN
  SELECT * INTO votante FROM votantes WHERE dni = mydni;
  dbms_output.put_line(votante.nombrecompleto||' con correo '||votante.email);
END;

