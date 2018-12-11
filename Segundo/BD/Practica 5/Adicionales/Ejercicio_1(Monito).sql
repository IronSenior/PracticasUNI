set serveroutput on;
DROP TABLE votantesAntiguos;
CREATE TABLE votantesAntiguos AS (SELECT * FROM votantes WHERE dni = NULL);
ALTER TABLE votantesAntiguos ADD Sueldo NUMBER;

declare
    CURSOR cur_votantes IS SELECT * FROM votantes;
    contador NUMBER := 0;
    sueldo NUMBER := 0;
begin
    FOR votante IN cur_votantes LOOP
        IF votante.fechanacimiento < '01/01/1980' THEN
          sueldo := 0;
          contador := contador + 1;
          IF votante.situacionlaboral = 'Activo' THEN 
            sueldo := 1000;
          END IF;
          INSERT INTO votantesAntiguos VALUES (votante.dni, votante.nombrecompleto, votante.estudiossuperiores, votante.situacionlaboral, votante.email, votante.localidad, votante.fechanacimiento, votante.telefono, sueldo);
          DBMS_OUTPUT.PUT_LINE('Votante insertado '||votante.nombrecompleto);
        END IF;
    END LOOP;
    dbms_output.put_line(contador||' votantes han sido insertados');
end;