#!/bin/bash
mkdir $HOME/tmp1
cd $HOME/tmp1

# Si por lo que sea la dirección que hay abajo no dispone del fichero, buscar otra con Google
wget -O httpd-2.4.38.tar.bz2 http://www.eu.apache.org/dist/httpd/httpd-2.4.38.tar.bz2
tar jxvf httpd-2.4.38.tar.bz2

# Bajamos y descomprimimos la última versión de las librerías APR
wget -O apr-1.6.5.tar.bz2 http://ftp.cixug.es/apache/apr/apr-1.6.5.tar.bz2
wget -O apr-util-1.6.1.tar.bz2 http://ftp.cixug.es/apache/apr/apr-util-1.6.1.tar.bz2
tar jxvf apr-1.6.5.tar.bz2
tar jxvf apr-util-1.6.1.tar.bz2

# Movemos las librerías a la carpeta de apache, para que éste las utilice
mv apr-1.6.5 ./httpd-2.4.38/srclib/apr
mv apr-util-1.6.1 ./httpd-2.4.38/srclib/apr-util

#Compilamos apache
cd httpd-2.4.38
./configure --prefix=$HOME/httpd --with-included-apr
make
make install

# Configurar bash para que al hacer logout se maten todos los procesos de Apache
if [ ! -f $HOME/.bash_logout ]
then
	echo -e "#!/bin/bash\nkillall -s KILL httpd" > $HOME/.bash_logout
elif [ -z "$(cat $HOME/.bash_logout | grep 'killall -s KILL httpd')" ]
then
	echo "killall -s KILL httpd" >> $HOME/.bash_logout
fi

#Borrar el directorio temporal de instalación
rm -rf $HOME/tmp1


