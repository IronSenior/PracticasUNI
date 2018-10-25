//ej1.c
//Implementar un proceso padre que cree 3 hijos y luego espera a que finalicen antes de finalizar él mismo

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
	int status;
	printf("Se van a crear 3 hijos de este proceso \n");

	for(int i=0; i<3; i++){
		if(!fork()){ //De esta manera creamos varios hijos que ejecutaran lo mismo
			printf("Soy el hijo %i\n", getpid());
			exit(EXIT_SUCCESS); //EXIT_SUCCESS indica que el proceso termino con exito (es igual a 0)
		}
	}
  	for(int i=0; i<3; i++){ //Esperará a que terminen los 3 procesos (No sé si esto está correcto)
		wait(&status);
	}

	printf("Procesos hijos terminados\n");
	return 0;
}
