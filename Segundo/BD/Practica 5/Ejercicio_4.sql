set serveroutput on;
declare
    CURSOR votantes IS SELECT v.dni, COUNT(c.votante) as veces FROM votantes v, consultas c
                            WHERE c.votante = v.dni
                            GROUP BY v.dni
                            HAVING COUNT(c.votante) > ((SELECT COUNT(c.votante) FROM consultas c)/(SELECT COUNT(dni) FROM votantes))
                            ORDER BY COUNT(c.votante) DESC;
begin
    FOR votante IN votantes LOOP
        dbms_output.put_line(votante.dni||' ha participado '||votante.veces);
    END LOOP;
end;