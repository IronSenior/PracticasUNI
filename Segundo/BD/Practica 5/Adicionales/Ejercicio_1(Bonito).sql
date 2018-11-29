set serveroutput on;
CREATE TABLE votantesAntiguos AS (SELECT * FROM votantes WHERE fechanacimiento < '01/01/1980');
ALTER TABLE votantesAntiguos ADD Sueldo NUMBER;
UPDATE votantesAntiguos SET sueldo=1500 WHERE situacionlaboral='Activo';
UPDATE votantesAntiguos SET sueldo=0 WHERE situacionlaboral<>'Activo';
declare
    CURSOR cur_votantes IS SELECT * FROM votantesantiguos;
    contador NUMBER := 0;
begin
    FOR votante IN cur_votantes LOOP
        dbms_output.put_line(votante.nombrecompleto||' ha sido insertado');
        contador := contador + 1;
    END LOOP;
    dbms_output.put_line(contador||' votantes han sido insertados');
end;

DROP TABLE votantesAntiguos;