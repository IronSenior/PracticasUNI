#!/bin/bash
#ARG1: DIRECTORIO

# Comprueba que ARG1 es un directorio
if [ $# -eq 1 ] && [ -d "$1" ];
then 
    # Cuenta los archivos terminados en .c y en .h
    cant1=$(find $1 -name "*.c" | wc -l)
    cant2=$(find $1 -name "*.h" | wc -l)

    # Imprime las cantidades para el usuario
    echo "tenemos $cant1 ficheros terminados en .c y $cant2 ficheros que terminan en .h"

    # Recorre los ficheros imprimiendo el numero de lineas y de caracteres
    for fichero in $(find $1 -type f -name "*.c" -o -type f -name "*.h")
    do
        if [ -f $fichero ];
            then
                echo "El fichero $fichero tiene $(cat $fichero | wc -l) lineas y $(cat $fichero | wc -m) caracteres"
        fi
    # Ordena por el numero de caracteres (En este caso la columna 8)
    done | sort -rn -k 8
else
    echo "Introduzca un directorio valido"
fi

