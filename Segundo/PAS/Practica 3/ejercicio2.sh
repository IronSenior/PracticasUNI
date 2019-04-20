#!/bin/bash
#ARG1: DIRECTORIO
#ARG2: TAMAÑO EN BYTES

echo "Nombre LongitudUsuario FechaModificacion FechaAcceso Tamaño Bloques Permisos Ejecutable"

if [ $# -eq 2 ]; 
then
	tmno=$2
else 
	tmno=0
fi

for fichero in $(find $1 -type f -size +"$tmno"c -o -type f -size "$tmno"c)
do 
	if [ -x "$fichero" ];
	then
		ejt=1
	else
		ejt=0
    fi

    echo "$(basename $fichero);$(stat -c %U $fichero | wc -m);$(stat -c '%y;%X;%s;%b;%A' $fichero);$ejt"

done | sort -k 5 -n -t ";"