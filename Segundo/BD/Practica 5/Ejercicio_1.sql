set serveroutput on;
declare
    CURSOR votantes IS SELECT * FROM votantes
        WHERE SUBSTR(votantes.dni,-1) = (votantes.localidad + 1);
    total NUMBER := 0;
begin
    open votantes;
    FOR votante IN votantes LOOP
        dbms_output.put_line(votante.nombrecompleto);
        total = total + 1;
    END LOOP;
    dbms_output.put_line('Hay un total de '||total||' votantes');
end;