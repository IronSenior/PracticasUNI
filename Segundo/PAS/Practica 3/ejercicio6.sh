#!/bin/bash
#Arg1: Carpeta

#Comprueba que se ha introducido un directorio valido
if [ $# -eq 0 ] || [ ! -d "$1" ];
then
	echo "Introduzca un directorio valido"
	exit 1
fi

# Función para listar archivos
listarArchivos ()
{
    echo "<ul>"
    for x in $(find $1 -maxdepth 1)
    do 
        if [ -d $x ];
        then
            echo "<li><strong>$x</strong></li>"
        else
            echo "<li>$x</li>"
        fi
    done 
    echo "<ul>"
}

# Imprime html al dinal de $1.html
echo "<html>" >> $1.html
echo "<head>" >> $1.html
echo "<title><h3>Listado de directorios de $1</h3></title>" >> $1.html
echo "</head>" >> $1.html
echo "<body>" >> $1.html
listarArchivos $1 >> $1.html
echo "</body>" >> $1.html
echo "</html>" >> $1.html

echo "Fichero html creado con éxito"