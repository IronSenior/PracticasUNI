set serveroutput on;
DECLARE
  mydni NUMBER := 30983712;
  votante votantes%rowtype;
BEGIN
  SELECT * INTO votante FROM votantes WHERE dni = mydni;
  dbms_output.put_line('Pepe'||SUBSTR(votante.nombrecompleto,INSTR(votante.nombrecompleto,' '),LENGTH(votante.nombrecompleto)));
END;