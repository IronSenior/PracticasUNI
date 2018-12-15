#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define V   1000

int buffer[V];
sem_t empty, full, mutex;


int main(int argc, char const *argv[]){

    //Thread identification
    pthread_t producerthread, consumerthread;
    int status;
    //Parameter for thread function
    int p = 1;
    //Predefinition of functions
    void *producer(void *);
    void *consumer(void *);
    //Returns values
    int *r_producer_value;
    int *r_consumer_value;

    srand(time(NULL));

    //Semaphores inicialization
    if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Failed to initialise sem mutex ");
    if((sem_init(&full, 0, 0)) == -1) perror("Error: Failed to initialise sem full ");
    if((sem_init(&empty, 0, V)) == -1) perror("Error: Failed to initialise sem empty ");


    //Producer Thread creation
    if ((status = pthread_create(&producerthread, NULL, producer, (void *) &p)))
        exit(status);

    //Producer Thread creation
    if ((status = pthread_create(&consumerthread, NULL, consumer, (void *) &p)))
        exit(status);
    
    //Waiting for threads
    pthread_join(producerthread, (void **) &r_producer_value);
    pthread_join(consumerthread, (void **) &r_consumer_value);

    printf("Valor suma del productor %i \n", *r_producer_value);
    printf("Valor suma del consumidor %i \n", *r_consumer_value);

    //Destoy Semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void *producer(void *p){

    //Variable declaration
    int i, dato, puntero;
    int suma = 0;
    int *to_return;
    extern int buffer[V];
    extern sem_t empty, full, mutex;


    for(i=0; i<1000; i++){
        dato = rand() % 1001; //generate data
        sem_wait(&empty);
        sem_wait(&mutex);
        puntero = (i+V)%V;  
        buffer[puntero] = dato;
        sem_post(&mutex);
        sem_post(&full);
        suma = suma + dato;
    }
    to_return = malloc(sizeof(int));
    *to_return = suma;

    pthread_exit((void *) to_return);
}

void *consumer(void *p){

    int i, dato, puntero;
    int suma = 0;
    int *to_return;
    extern int buffer[V];
    extern sem_t empty, full, mutex;

    for(i=0; i<1000; i++){
        sem_wait(&full);
        sem_wait(&mutex);
        puntero = (i+V)%V;
        dato =  buffer[puntero];
        sem_post(&mutex);
        sem_post(&empty);
        suma = suma + dato;
    }

    //Para hacer el return de los hilos hay que reservar memoria
    to_return = malloc(sizeof(int));

    *to_return = suma;

    pthread_exit((void *) to_return);
}

