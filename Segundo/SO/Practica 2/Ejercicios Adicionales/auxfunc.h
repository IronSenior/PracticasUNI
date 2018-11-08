//Fichero de cabecera de funciones auxialiares
//José Márquez Doblas (GG2)

#ifndef AUXFUNC_H
#define AUXFUNC_H


#define MATRIXI 3
#define MATRIXJ 3
#define VECTOR  3

void get_matrix(int** matrix);

void get_vector(int* vector);

void multiplyBase(int* vector, int** matrix, int* result);

void *multiplyThread(int* vector, int** matrix, int* result, void *thread_index);

void print_result(int* result);

#endif