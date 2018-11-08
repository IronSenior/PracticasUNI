//Fichero de cabecera de funciones auxialiares
//José Márquez Doblas (GG2)

#ifndef AUXFUNC_H
#define AUXFUNC_H


#define MATRIXI 3
#define MATRIXJ 3
#define VECTOR  3

//Creacion del vector
int vector[VECTOR];

int matrix[MATRIXI][MATRIXJ];

int result[VECTOR];

void get_matrix(int** matrix);

void get_matrix_thread();

void get_vector(int* vector);

void get_vector_thread();

void multiplyBase(int* vector, int** matrix, int* result);

void *multiplyThread(void *thread_index);

void print_result(int* result);

#endif