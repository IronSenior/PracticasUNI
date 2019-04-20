#ARG1:ARG2...ARGN ficheros

date=$(date +%s) # Segundos que han pasado desde el 1/1/1970

#comprobar si la carpeta existe y demás

for x in $(find copia.seg -type f)
do 
    modif=$(stat $x -c %X)
    time=$date-$modif
    if [$time -gt 200]
    then 
        rm -f $X
    fi 
done
tar -czf copia.seg/copia-$(whoiam)-$date.tar.gz $*
