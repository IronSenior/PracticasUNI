set serveroutput on;
declare
    CURSOR votantes IS SELECT * FROM votantes ORDER BY dni DESC;
    votante1 votantes%rowtype;
    votante2 votantes%rowtype;
    cuenta NUMBER := 1;
begin
    open votantes;
    FETCH votantes INTO votante1;
    FETCH votantes INTO votante2;
    dbms_output.put_line(votante1.dni||' va antes de '||votante2.dni);
    LOOP
        votante1 := votante2;
        FETCH votantes INTO votante2;
        IF (votantes%NOTFOUND) THEN 
          dbms_output.put_line('El mas pequeño es '||votante2.dni);
          EXIT;
        END IF;
        dbms_output.put_line(votante1.dni||' va antes de '||votante2.dni);
    END LOOP;
end;