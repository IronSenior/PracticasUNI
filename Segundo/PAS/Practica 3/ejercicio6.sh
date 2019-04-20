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

echo "<html>" >> $1.html
echo "<head>" >> $1.html
echo "<title><h3>Listado de directorios de $1</h3></title>" >> $1.html
echo "</head>" >> $1.html
echo "<body>" >> $1.html
listarArchivos $1 >> $1.html
echo "</body>" >> $1.html
echo "</html>" >> $1.html