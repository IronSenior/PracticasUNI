#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define V   5   //Buffer
#define C   4   //Number of consumers
#define n_products  1000 //Number of products

int buffer[V];
sem_t empty, full, mutex;


int main(int argc, char const *argv[]){

    //Thread identification
    pthread_t producerthread;
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

    srand(time(NULL));

    //Semaphores inicialization
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, 9);
    sem_init(&full, 0, 0);

    extern int buffer[V];

    for(i=0;i<V;i++){
        buffer[i] = 0;
    }

    //Producer Thread creation
    if ((status = pthread_create(&producerthread, NULL, producer, (void *) &i)))
        exit(status);

    //Producer Thread creation
    for(i=0; i<C; i++){
        if ((status = pthread_create(&consumers[i], NULL, consumer, (void *) &i)))
            exit(status);
    }

    //Waiting for threads
    pthread_join(producerthread, (void **) &r_producer_value);
    printf("Value returned by producer %lu: %d \n", producerthread, *r_producer_value);

    for(i=0; i<C; i++){
        pthread_join(consumers[i], (void **) &r_consumer_value);
        printf("Value returned by consumer %lu: %d \n", consumers[i], *r_consumer_value);
    }

    //Destoy Semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void *producer(void *p){

    //Variable declaration
    int i, j, data;
    int *to_return;
    extern int buffer[V];
    int sum = 0;
    extern sem_t empty, full, mutex;


    for(i=0; i<(n_products/V); i++){
        sem_wait(&mutex);
        for(j=0; j<V; j++){
            data = rand() % 1001;
            buffer[j] = data;
            sum += data;
        }
        sem_post(&mutex);
        sem_wait(&empty);
    }

    //return
    to_return = malloc(sizeof(int));
    *to_return = sum;

    pthread_exit((void *) to_return);
}

void *consumer(void *p){

    int i, data, j, *pthread_number;
    int sum = 0;
    int number = 14;
    int *to_return;
    extern int buffer[V];
    extern sem_t empty, full, mutex;

    pthread_number = (int *) p;

    for(i=0; i<(n_products/V); i++){
        sem_wait(&mutex);
        for(j=0; j<V; j++){
            data =  buffer[j];
            sum += data;
            data = 0;
        }
        sem_post(&empty);
        sem_post(&mutex);
    }

    //Return
    to_return = malloc(sizeof(int));

    *to_return = sum;

    pthread_exit((void *) to_return);
}

