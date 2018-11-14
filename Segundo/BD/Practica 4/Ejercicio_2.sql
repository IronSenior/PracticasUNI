set serveroutput on;
DECLARE
  mydni NUMBER := 30983712;
  votante votantes%rowtype;
BEGIN
  SELECT * INTO votante FROM votantes WHERE dni = mydni;
  dbms_output.put_line( SUBSTR(votante.nombrecompleto,1,INSTR(votante.nombrecompleto,' '))||'con correo '||votante.email);
END;

