//ej1.c
//Los tres hijos comparten un vector de 100 enteros. Cada uno de ellos ha de realizar una de las siguientes tareas:
//
//Pedir un índice del vector y un valor entero por teclado y almacenar en la posición correspondiente el valor leído. 
//Esta operación se ha de repetir 10 veces.
//
//Cambiar aleatoriamente un elemento del vector y bloquearse durante 1 segundo. Esta operación se ha de repetir 100 veces.
//
//Sumar   todos   los   elementos   del   vector,   mostrar   la   suma   por   pantalla   y   luego bloquearse durante 30 segundos. 
//Esta operación se ha de repetir 5 veces.

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
	int status;
    int hijo = 0;

    printf("Se van a crear los tres hijo\n")
	for(int i=0; i<3; i++){
        hijo ++;
		if(!fork()){ //De esta manera creamos varios hijos que ejecutaran lo mismo
			func_hijo(hijo); //Los tres hijo llamaran a la misma funcion que hará una cosa distinta para cada uno
			exit(EXIT_SUCCESS); //EXIT_SUCCESS indica que el proceso termino con exito (es igual a 0)
		}
	}
  	for(int i=0; i<3; i++){ //Esperará a que terminen los 3 procesos (No sé si esto está correcto)
		wait(&status);
	}

	printf("Procesos hijos terminados\n");
	return 0;
}

//Cada hijo ejecutará una tarea distinta
bool func_hijo(int hijo){
    switch(hijo){
        case 1: {
            printf("Introduzca la posición para insertar el valor")
        }
    }
}