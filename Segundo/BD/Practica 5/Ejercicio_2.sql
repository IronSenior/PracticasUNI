set serveroutput on;
declare
    CURSOR votantes IS 
        SELECT v.nombrecompleto, DECODE(l.provincia, 1, 'Madrid', l.nombre) as localidad FROM votantes v, localidades l 
            WHERE l.idlocalidad = v.localidad;
    total NUMBER := 0;
begin
    FOR votante IN votantes LOOP
        IF votante.localidad = 'Madrid' THEN total := total + 1;
        END IF;
        dbms_output.put_line(votante.nombrecompleto||' '||votante.localidad);
    END LOOP;
    dbms_output.put_line('Hay un total de '||total||' votantes de Madrid');
end;