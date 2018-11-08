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

    multiplyBase(vector, matrix, result);
    print_result(result);

    for(int i = 0;i < MATRIXI;i++){
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);
    return 0;
}
