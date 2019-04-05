echo "El numero de argumentos en la carpeta es $(find $1 -maxdepth 1 -type f | wc -l)"

echo "$(who | awk '{print $1}' | sort | uniq)"
#Hacer el read

echo "El caracter $c aparece "
for x in $(find)
do
    echo "$(basename $x)"
done | grep $c -o | wc -l

echo "$(grep $c -o fichero.temp | wc -l) veces en nombre de ficheros o carpetas contenidas en la carpeta actual"