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
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char const *argv[])
{
	int status;
    int hijo = 0;
	int *vector;
	key_t key;
	struct shmid_ds buf;
	int shmid;
	void func_hijo(int);

    // Memoria compartida
    key = ftok("ej2.c", 1);
    if ((shmid = shmget(key, 100*sizeof(int), IPC_CREAT | 0777)) == -1)
	exit(1);

    vector = (int *) shmat(shmid, NULL, 0);

	//Inicializamos el vector con 100 valores aleatorios
	for(int i=0; i<100; i++){
		vector[i] = rand() % 1000;
	}

	//Creación de procesos hijos
    printf("Se van a crear los tres hijo\n");
	for(int i=0; i<3; i++){
		if(!fork()){
			func_hijo(i);
		}
	}

	//El proceso padre esperará a los tres procesos
  	for(int i=0; i<3; i++){
		pid_t pid = wait(&status);
		printf("Finalizado proceso %i con valor %i\n", pid, WEXITSTATUS(status));
	}

	//Libera memoria del vector
	shmdt(vector);
	//Y lo destruye
	shmctl(shmid, IPC_RMID, &buf);

	printf("Procesos hijos terminados\n");
	return 0;
}

//Cada hijo ejecutará una tarea distinta
//Hay que compartir memoria
void func_hijo(int hijo){

	int *vector;
	int shmid;
	key_t key;
	int index, value, suma;


	// Memoria compartida
    key = ftok("ej2.c", 1);
    if ((shmid = shmget(key, 100*sizeof(int), 0)) == -1)
	perror("Child: ");

    vector = (int *) shmat(shmid, NULL, 0);


    switch(hijo){
        case 0: {//Ejecución del proceso 1
			for (int i=0; i<10; i++){
				//Pide al usuario el indice y el valor
				printf("Introduzca la posición para insertar el valor\n");
				scanf("%i", &index);
				printf("Introduzca el valor que quiere introducir\n");
				scanf("%i", &value);
				//Comprueba que el indice es correcto 
				if ((index < 100) && (index >= 0)){
					vector[index] = value;
				}else{
					printf("Indice no valido\n");
				}
			}
        }
		case 1: {//Ejecución del proceso 2
			for (int i=0; i<100; i++){
				//Asigna los valores aleatorios
				index = rand() %100;
				value = rand() %1000;
				vector[index] = value;
				sleep(1); //Se espera un segundo 
			}
        }
		case 2: {//Ejecución del proceso 3
			for(int i=0; i<5; i++){
				suma = 0;//Ejecución del proceso 3
				for(int j=0; i<100; i++){
					suma += vector[i];
				}
				printf("La suma del vector es %i\n", suma);
				sleep(30); //Se espera 30 segundos
			}
        }
    }
	
	shmdt(vector);
	exit(hijo);

}