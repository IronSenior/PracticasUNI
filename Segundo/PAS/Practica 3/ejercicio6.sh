#!/bin/bash
#Arg1: Carpeta

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

echo "<html>"
echo "<head>"
echo "<title><h3>Listado de directorios de $1</h3></title>" 
echo "</head>"
echo "<body>"
listarArchivos $1
echo "</body>"
echo "</html>"