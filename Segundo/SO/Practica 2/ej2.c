#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

double counter = 0;

#define ITER	1000
#define NHILOS	4 //Numero de hilos que se van a crear

bool eligiendo[NHILOS];
int numero[NHILOS];

void initialize_elig_and_num(){
    extern int numero[];
    extern bool eligiendo[];
    for (int i = 0; i<NHILOS; i++){
        eligiendo[i] = false;
        numero[i] = false;
    }
}

//Funcion que calcula el maximo del vector numero[]
int maximo(){
    extern int numero[];
    int max = 0;

    for (int i=0; i<NHILOS; i++){
        if(numero[i]> max){
            max = numero[i];
        }
    }
    return max;
}



int main()
{
    pthread_t hilos[NHILOS]; //Identificadores de los hilos
    int status, i, v[NHILOS];
    extern double counter;
    void *adder(void *);
    double *r_value;

    initialize_elig_and_num();

    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
	v[i] = i;
	if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
	    exit(status);
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
	    pthread_join(hilos[i], (void **) &r_value);
	    printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    // Final result
    fprintf(stdout, "Cuenta final (Tiene que ser 4000) = %f\n", counter);

    return 0;
}

void *adder(void *p) //Se le pasa un void * siempres
{
    extern double counter;
    extern bool eligiendo[];
    extern int numero[];
    int *id;
    double l, *to_return;

    //Como le hemos pasado un void* hay que hacer un casting a int
    id = (int *) p;

    //Sección Crítica (Algoritmo de Lamport)
    for (int i = 0; i < ITER; i++) {

        //Cola donde de coge numero
        eligiendo[*id] = true;
        numero[*id] = maximo() + 1;
        eligiendo[*id] = false;

        //Zona de espera
        for(int j=0; j<NHILOS; j++){
            while(eligiendo[j]);
            while((numero[j] != 0) && ((numero[j] < numero[*id]) || ((numero[j] == numero[*id]) && (j<*id))));
        }

        //Sección Crítica
        l = counter;
        fprintf(stdout, "Hilo %d: %f\n", *id, counter);
        l++;
        counter = l;
        //Final Seccion Crítica

        //IMPORTANTE: hay que poner el numero a 0 
        numero[*id] = 0;
    }
    

    //Para hacer el return de los hilos hay que reservar memoria
    to_return = malloc(sizeof(double));

    *to_return = counter;

    pthread_exit((void *) to_return);
}
