
#include <stdio.h>
#include <sys/time.h>

#define NUMBER_OF_OPERATIONS 10000

#define OPERAND_A 5
#define OPERAND_B 5


int suma(){
    int result;
    result = OPERAND_A + OPERAND_B;
}


int main(int argc, char const *argv[])
{
    struct timeval t, t2;
    int microsegundos;
    gettimeofday(&t, NULL);

    int counter = 0;

    while(counter < NUMBER_OF_OPERATIONS){
        suma();
        counter++;
    }

    gettimeofday(&t2, NULL);
    microsegundos = ((t2.tv_usec - t.tv_usec)  + ((t2.tv_sec - t.tv_sec) * 1000000.0f));
    printf("Tardo %i microsegundos", microsegundos);

    return 0;
}

