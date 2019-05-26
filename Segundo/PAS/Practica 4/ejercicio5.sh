# Lee ficheros del directorio /proc/

imprimeProcesador (){
    grep "model name " /proc/cpuinfo
}

imprimeProcesador