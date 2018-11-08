#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "auxfunc.h"

int main(int argc, char const *argv[]){
    extern int vector[VECTOR];
    extern int matrix[MATRIXI][MATRIXJ];
    extern int result[VECTOR];

    get_vector_thread();
    get_matrix_thread(); 

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
    return 0;
}
