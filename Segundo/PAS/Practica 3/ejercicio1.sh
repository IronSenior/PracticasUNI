#!/bin/bash
#ARG1: DIRECTORIO

if [ -d $1 ];
then 
    cant1=$(find $1 -name "*.c" | wc -l)
    cant2=$(find $1 -name "*.h" | wc -l)

    echo "tenemos $cant1 ficheros terminados en .c y $cant2 ficheros que terminan en .h"

    for fichero in $(find $1 -type f -name "*.c" -o -type f -name "*.h")
    do
        echo "El fichero $fichero tiene $(cat $fichero | wc -l) lineas y $(cat $fichero | wc -m) caracteres"
    done | sort -rn -k 8
else
    echo "No has introducido un directorio"
fi

