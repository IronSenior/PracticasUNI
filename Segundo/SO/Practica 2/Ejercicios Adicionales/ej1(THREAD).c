#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "auxfunc.h"

int main(int argc, char const *argv[]){

    if (MATRIXI != VECTOR){perror("IMPOSIBLE MULTIPLICA, SIZE ERROR");}
    //Creacion del vector
    int *vector;
    vector = (int*) malloc(VECTOR*sizeof(int));
    if(vector == NULL) { perror(""); }

    //Creacion de la matriz
    int **matrix;
    matrix = (int**) malloc((MATRIXI)*sizeof(int));
    if(matrix == NULL){perror("");}
	for (int i = 0;i < MATRIXI;i++){
		matrix[i] = (int*)malloc(MATRIXJ*sizeof(int)); 
		if(matrix[i] == NULL){perror("Error: ");}
	}

    get_vector(vector);
    get_matrix(matrix); 

    int *result;
    result = (int*) malloc(VECTOR*sizeof(int));
    if (result == NULL){perror("");}

    // Create NHILOS threads
    pthread_t hilos[MATRIXI];
    int status, i, v[MATRIXI];
    double *r_value;
    for (i = 0; i < MATRIXI; i++) {
        v[i] = i;
        if ((status = pthread_create(&hilos[i], NULL, multiplyThread, (void *) &v[i])))
            exit(status);
    }

    // Wait threads
    for (i = 0; i < MATRIXI; i++) {
        pthread_join(hilos[i], (void**) r_value);
        printf("%lu thread is finished\n", hilos[i]);
    }

    print_result(result);

    for(int i = 0;i < MATRIXI;i++){
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);
    return 0;
}
