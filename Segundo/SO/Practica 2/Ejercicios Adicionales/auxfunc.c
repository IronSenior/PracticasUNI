//Funciones auxiliares para los ejercicios adicionales
//José Márquez Doblas (GG2)

#include "auxfunc.h"
#include <stdio.h>

void get_matrix(int** matrix){
    int i, j;
    int element;
    for (i = 0; i < MATRIXI; i++){
        for (j = 0; j < MATRIXJ; j++){
            printf("Introduzca el elemento %i:%i de la matriz\n", (i+1), (j+1));
            scanf("%i", &element);
            matrix[i][j] = element;
        }
    }
}

void get_vector(int* vector){
    int i;
    int element;
    for (i = 0; i < VECTOR; i++){
        printf("Introduzca el elemento %i del vector\n", (i+1));
        scanf("%i", &element);
        vector[i] = element;
    }
}

void multiplyBase(int* vector, int** matrix, int* result){
    int i, j;
    for (i = 0; i < MATRIXI; i++){
        for (j = 0; j < MATRIXJ; j++){
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

void print_result(int* result){
    int i;
    printf("El resultado de la multiplicacion es: ( ");
    for (i = 0; i < VECTOR; i++){
        printf("%i ", result[i]);
    }
    printf(")\n");
}