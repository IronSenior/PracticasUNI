#!/bin/bash

# Impreme el numero de ficheros que hay en la carpeta actual
echo "El numero de ficheros en la carpeta es $(find $1 -maxdepth 1 -type f | wc -l)"

# Imprime los usuarios activos del sistema
echo "Usuario logueado --> $(who | awk '{print $1}' | sort | uniq)"

# Pedir al usaurio el caracter
read -t5 -n1 -p "Introduzca el caracter a buscar " c
if [ "$c" == "" ]; 
then
	c="a"
fi

#Cuanta las veces que aparece dicho caracter
for x in $(find)
do
    echo -n "$(basename $x)"
done | grep $c -o | wc -l > fichero.temp

echo -e "\nEl carácter $c aparece $(cat fichero.temp) veces en nombres de ficheros o carpetas contenidos en la carpeta actual"
rm fichero.temp