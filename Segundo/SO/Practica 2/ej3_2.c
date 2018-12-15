#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define V   5   //Buffer
#define P   5  //Number of producers
#define C   4   //Number of consumers
#define n_products  10 //Number of products per producer

int buffer[V];
int sum_consumers = 0;
int sum_producers = 0;
int index_producers = 0;
int index_consumers = 0;
sem_t empty, full, mutex;

//Divide the total number of products between the consumers
int number_consumptions(int pthread_number){
    int surplus = 0;
    int consumptions = 0;

    //Calculate number of consumptions per consumer
    consumptions = (P*n_products)/C;

    //Calculate the surplus
    surplus = (P*n_products)%C;
    //Assigns the surplas to the last consumer thread
    if (pthread_number == (C-1)){
        return (consumptions + surplus);
    }
    else return consumptions;
}


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
    extern int sum_producers;
    extern int sum_consumers;

    srand(time(NULL));

    //Semaphores inicialization
    if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Failed to initialise sem mutex ");
    if((sem_init(&full, 0, 0)) == -1) perror("Error: Failed to initialise sem full ");
    if((sem_init(&empty, 0, V)) == -1) perror("Error: Failed to initialise sem empty ");

    //Producer Thread creation
    int producer_numbers[C];
    for(i=0; i<P; i++){
        producer_numbers[i] = i;
        if ((status = pthread_create(&producers[i], NULL, producer, (void *) &producer_numbers[i])))
            exit(status);
    }

    //Consumer Thread creation
    int consumer_numbers[C];
    for(i=0; i<C; i++){
        consumer_numbers[i] = i;
        if ((status = pthread_create(&consumers[i], NULL, consumer, (void *) &consumer_numbers[i])))
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

    //Results
    printf("Suma productores: %d\n", sum_producers);
    printf("Suma consumidores: %d\n", sum_consumers);
    

    //Destoy Semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void *producer(void *p){

    //Variable declaration
    int i, data;
    int *to_return;
    extern int buffer[V];
    extern int sum_producers;
    extern int index_producers;
    extern sem_t empty, full, mutex;


    for(i=0; i<n_products; i++){
        data = rand() % 1001;
        sem_wait(&empty);
        sem_wait(&mutex);
        index_producers++;
        buffer[index_producers%V] = data;
        sum_producers += data;
        sem_post(&mutex);
        sem_post(&full);
    }

    //return
    to_return = malloc(sizeof(int));
    *to_return = sum_producers;

    pthread_exit((void *) to_return);
}

void *consumer(void *p){

    int i, *pthread_number, consumos;
    extern int sum_consumers;
    extern int index_consumers;
    int *to_return;
    extern int buffer[V];
    extern sem_t empty, full, mutex;

    //Calculate the number of consumptions per consumer
    pthread_number = (int *) p;
    consumos = number_consumptions(*pthread_number);

    for(i=0; i<consumos; i++){
        sem_wait(&full);
        sem_wait(&mutex);
        index_consumers++;
        sum_consumers += buffer[index_consumers%V];
        buffer[index_consumers%V] = 0;
        sem_post(&mutex);
        sem_post(&empty);
    }

    //Return
    to_return = malloc(sizeof(int));

    *to_return = sum_consumers;

    pthread_exit((void *) to_return);
}

