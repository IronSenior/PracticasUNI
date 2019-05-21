#ARG1 : Fichero de IP

# Recorre el fichero de ips realizando ping
for ip in $(grep -Eo '[0-9]{,3}\.[0-9]{,3}\.[0-9]{,3}\.[0-9]{,3}' $1)
do 
    ms=$(ping -c 1 $ip | grep -Eo '[0-9]+ms$')
    # Imprime los ms que ha tardado cada ping
    echo "$ip ha tardado $ms"
    
# Ordena la salida por tiempo
done | sort -k 4 -n -t " "