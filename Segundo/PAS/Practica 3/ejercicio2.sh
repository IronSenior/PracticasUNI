#!/bin/bash
#ARG1: DIRECTORIO
#ARG2: TAMAÑO EN BYTES

# Imprime la cabecera
echo "Nombre LongitudUsuario FechaModificacion FechaAcceso Tamaño Bloques Permisos Ejecutable"

# Comprueba si se ha introducido el argumento opcional
if [ $# -eq 2 ]; 
then
	tmno=$2
else 
    # Si no se ha introducido se asigna un 0
	tmno=0
fi

# Recorre los archivos que cumplen con los requisitos
for fichero in $(find $1 -type f -size +"$tmno"c -o -type f -size "$tmno"c)
do 
    #Asigan una variable para imprimir si es ejecutable o no
	if [ -x "$fichero" ];
	then
		ejt=1
	else
		ejt=0
    fi

    # Imprime la linea con el formato deseado
    echo "$(basename $fichero);$(stat -c %U $fichero | wc -m);$(stat -c '%y;%X;%s;%b;%A' $fichero);$ejt"

# Ordena la salida conforme al tamaño (En este caso la columna 5)
done | sort -k 5 -n -t ";"