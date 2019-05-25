# ARG1 Fichero

echo '********* -- 1'
echo "Mostrar duración de las películas"
grep -E '... ..min\>' $1

echo '********* -- 2'
echo "Mostrar la linea del pais de la película"
grep -E '\-.*\-' $1

echo '********* -- 3'
echo "Mostrar solamente el pais de la película"
grep -Eo '\-(.*)\-' $1 | grep -Eo '[A-Za-z]* *[A-Za-z]*' 

echo '********* -- 4'
echo "Contar cuantas peiculas son del 2016 y cuantas del 2017"
echo "Hay $(grep -E -c '../../2016' $1) peliculas de 2016 y $(grep -E -c '../../2017' $1) de 2017"

echo '********* -- 5'
echo "Mostrar todo el documento pero sin lineas vacias"
grep -v -E '^\s*$' $1

echo '********* -- 6'
echo "Mostrar todas las lineas que empiezan por E haya o espacios delante"
grep -E '^ *E' $1

echo '********* -- 7'
echo "Lineas que contienen l t o d con vocales en medio"
grep -E -e '[a-z]*t[a-u]t[a-z]*' -e '[a-z]*d[a-u]d[a-z]*' -e '[a-z]*l[a-u]l[a-z]*' $1

echo '********* -- 8'
echo "Lineas que tienen 6 o más aes"
grep -E '(.*a.*){6,}' $1

echo '********* -- 9'
echo "Lineas que terminan en ... y no empiezan por espacio"
grep -E '^[^ ].*\.\.\.$' $1

echo "********* -- 10"
echo "Utilizando sed , entrecomillar las vocales con tilde"
cat $1 | sed 's/á/"á"/' | sed 's/é/"é"/' | sed 's/í/"í"/' | sed 's/ó/"ó"/' | sed 's/ú/"ú"/'
