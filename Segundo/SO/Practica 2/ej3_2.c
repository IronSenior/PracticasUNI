#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define V   5   //Buffer
#define P   1   //Number of producers
#define C   3   //Number of consumers

int buffer[V];
int suma_productores = 0;
int suma_consumidores = 0;
int indice_productores = -1;
int indice_consumidores = -1;
sem_t empty, full, mutex;


int main(int argc, char const *argv[]){

    //Thread identification
    pthread_t producers[P];
    pthread_t consumers[C];
    int status;
    //iterator
    int i;
    //Predefinition of functions
    void *producer(void *);
    void *consumer(void *);
    //Returns values
    int *r_producer_value;
    int *r_consumer_value;
    extern int suma_consumidores;
    extern int suma_productores;

    srand(time(NULL));

    //Semaphores inicialization
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, V);
    sem_init(&full, 0, 0);

    //Producer Thread creation
    for(i=0; i<P; i++){
        if ((status = pthread_create(&producers[i], NULL, producer, (void *) &i)))
            exit(status);
    }

    //Producer Thread creation
    for(i=0; i<C; i++){
        if ((status = pthread_create(&consumers[i], NULL, consumer, (void *) &i)))
            exit(status);
    }

    //Waiting for threads
    for(i=0; i<P; i++){
        pthread_join(producers[i], (void **) &r_producer_value);
        printf("Value returned by producer %lu: %d \n", producers[i], *r_producer_value);
    }
    for(i=0; i<C; i++){
        pthread_join(consumers[i], (void **) &r_consumer_value);
        printf("Value returned by consumer %lu: %d \n", consumers[i], *r_consumer_value);
    }

    printf("Suma productores: %d\n", suma_productores);
    printf("Suma consumidores: %d\n", suma_consumidores);

    //Destoy Semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void *producer(void *p){

    //Variable declaration
    int i, dato, puntero;
    int *to_return;
    extern int buffer[V];
    extern int suma_productores;
    extern int indice_productores;
    extern sem_t empty, full, mutex;


    for(i=0; i<1000; i++){
        dato = rand() % 1001; //generate data
        sem_wait(&empty);
        sem_wait(&mutex);
        indice_productores = (indice_productores+1)%V;
        buffer[indice_productores] = dato;
        suma_productores += dato;
        sem_post(&mutex);
        sem_post(&full);
    }
    to_return = malloc(sizeof(int));
    *to_return = suma_productores;

    pthread_exit((void *) to_return);
}

void *consumer(void *p){

    int i, dato, puntero;
    extern int suma_consumidores;
    extern int indice_consumidores;
    int *to_return;
    extern int buffer[V];
    extern sem_t empty, full, mutex;

    for(i=0; i<1000; i++){
        sem_wait(&full);
        sem_wait(&mutex);
        indice_consumidores = (indice_consumidores+1)%V;
        dato =  buffer[indice_consumidores];
        suma_consumidores += dato;
        sem_post(&mutex);
        sem_post(&empty);
    }

    //Para hacer el return de los hilos hay que reservar memoria
    to_return = malloc(sizeof(int));

    *to_return = suma_consumidores;

    pthread_exit((void *) to_return);
}

