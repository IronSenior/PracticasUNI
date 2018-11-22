#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>

#define V   5
#define NHILOS 2

int buffer[V];
sem_t empty, full, mutex;


main(int argc, char const *argv[]){

    pthread_t producerthread; //Identificadores de los hilos
    int status;
    int p = 1;
    void *producer(void *);
    double *r_value;
    srand(time(NULL));

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, V);
    sem_init(&full, 0, 0);

    //Producer Thread creation
    if ((status = pthread_create(&producerthread, NULL, producer, (void *) &p)))
        exit(status);

    //Producer Thread creation
    if ((status = pthread_create(&producerthread, NULL, producer, (void *) &p)))
        exit(status);
    
    //Waiting for threads
    pthread_join(producerthread, (void **) &r_value);
    //pthread_join(consumerthread, (void **) &r_value);
    return 0;
}

void *producer(void *p){

    int i, dato, puntero;
    extern int buffer[V];
    extern sem_t empty, full, mutex;

    for(i=0; i<1000; i++){
        dato = rand() % 1001; //generate data
        sem_wait(&empty);
        sem_wait(&mutex);
        sem_getvalue(&full, &puntero); //No Error check
        buffer[puntero] = dato;
    
    }



}

