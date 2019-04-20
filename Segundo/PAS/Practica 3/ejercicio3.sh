#!/bin/bash
#ARG1: DIRECTORIO
#ARG2: umbral1
#ARG3: umbral2


#Funcion para comprobar que la carpeta existe
comprobar_carpeta ()
{
    if [ -e $1 ];
    then
        echo "$carpeta ya existe, borrando y creando de nuevo"
        rm -r $1
        mkdir $1
    else
        mkdir $1
    fi    
}

#Comprobación de argumentos
if [ $# -eq 3 ]; 
then
	umbral1=$2
    umbarl2=$3
elif [ $# -eq 2 ];
then
	umbral1=$2
    umbral2=100000
else
    umbral1=10000
    umbral2=100000
fi

# Reasignación por si se han introducido mal
if [ $umbral1 -ge $umbral2 ];
then
	aux=$umbral2
	umbral2=$umbral1
	umbral1=$aux
fi

# Creación de las carpetas 
comprobar_carpeta pequenos
comprobar_carpeta medianos
comprobar_carpeta grandes


# Copia de los pequeños
echo "Copiando archivos pequeños"
for fichero in $(find $1 -type f -size -"$umbral1"c)
do  
    cp $fichero pequenos
done

# Copia de los medianos
echo "Copiando archivos medianos"
for fichero in $(find $1 -type f -size +"$umbral1"c -and -size -"$umbral2"c)
do  
    cp $fichero medianos
done

# Copia de los grandes
echo "Copiando archivos grandes"
for fichero in $(find $1 -type f -size +"$umbral2"c)
do  
    cp $fichero grandes
done


