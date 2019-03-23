#include <stdio.h>
#include <stdlib.h> //exit, rand, srand
#include <unistd.h> //pipe, close, fork, usleep, read, write, getpid, getppid
#include <sys/wait.h> //wait
#include <ctype.h>
#include <errno.h> //Control de errores
#include <string.h> //strerror
#include <time.h> //Para la semilla del generador de aleatorios

int esPrimo(int numero);
int main(){

    pid_t flag;
    int status;
    int n1;
    int n2;
    int fildes2[2];
    int fildes[2];
    const int BSIZE = 100;
    char buf[BSIZE];
    char message[BSIZE];
    ssize_t nbytes;


    status = pipe(fildes);
    status = pipe(fildes2);
    if (status == -1 ) 
    {
        perror("Error en pipe"); 
        exit(EXIT_FAILURE);
    }

    status = pipe(fildes2);
    if (status == -1 ) 
    {
        perror("Error en pipe"); 
        exit(EXIT_FAILURE);
    }

    switch (fork()) 
    {
        case -1: // Ocurrió un error al hacer fork()
            perror("No se ha podido crear el proceso hijo...");
            exit(EXIT_FAILURE);

        case 0: // El hijo lee desde la tubería, no necesitamos escribir ni leer
            if ((close(fildes[1]) == -1) || (close(fildes2[0]) == -1)){
                perror("Error en close"); 
                exit(EXIT_FAILURE);
            }

            // Leer usando READ
            nbytes = read(fildes[0], buf, BSIZE);
            if (nbytes == -1)
            {
                perror("Error en read"); 
                exit(EXIT_FAILURE);
            }
            else if (nbytes == 0) //read() no ha leido nada -> Se ha llegado a EOF -> El padre ha cerrado la tuberia
                printf("[HIJO]: Detecto que mi padre ha cerrado la tuberia...\n"); 
            else{
                n1 = atoi(strtok(buf, ";"));
                printf("%s\n", buf);
                //n2 = atoi(strtok(buf, ";"));
                message[BSIZE] = "no-primos";
                if ((esPrimo(n1)) && (esPrimo(n2))){
                    message[BSIZE] ="primos";
                    if((n1-n2==2)||(n2-n1==2)){
                        message[BSIZE] = "gemelos";
                    }
                    
                }
                printf("%s\n", message);
                if ( write(fildes2[1], message, 14) == -1)
                {
                    perror("Error en write"); 
                    exit(EXIT_FAILURE);
                }
            }
            if ((close(fildes[0]) == -1)||(close(fildes2[1])==-1)) //Se termina de leer -> Cerramos filfes[0]
            {
                perror("Error en close"); 
                exit(EXIT_FAILURE);
            }
            printf("[HIJO]: Tuberia cerrada.\n"); 

            exit(EXIT_SUCCESS);

        
        default: // El padre escribe en la tubería
            // No se necesita leer
            if ((close(fildes[0]) == -1) || (close(fildes2[1]) == -1))
            {
                perror("Error en close"); 
                exit(EXIT_FAILURE);
            }

            printf("Escribe dos numero separados por ; EJ: 3;4\n");
            scanf("%s", message);
            if ( write(fildes[1], message, 14) == -1)
            {
                perror("Error en write"); 
                exit(EXIT_FAILURE);
            }

            nbytes = read(fildes2[0], buf, BSIZE);
            if (nbytes == -1)
            {
                perror("Error en read"); 
                exit(EXIT_FAILURE);
            }
            else if (nbytes == 0) //read() no ha leido nada -> Se ha llegado a EOF -> El padre ha cerrado la tuberia
                printf("[HIJO]: Detecto que mi padre ha cerrado la tuberia...\n"); 
            else
                printf("%s", buf);

            // El hijo verá FEOF (por hacer close)
            if ((close(fildes[1]) == -1)||(close(fildes2[0])==-1))
            {
                perror("Error en close"); 
                exit(EXIT_FAILURE);
            }
            else
                printf("[PADRE]: Tuberia cerrada.\n"); 
                
            while ( (flag=wait(&status)) > 0 ) 
            {
                if (WIFEXITED(status)) 
                {
                    printf("Proceso Padre, Hijo con PID %ld finalizado, status = %d\n", (long int)flag, WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {  //Para seniales como las de finalizar o matar
                    printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)flag, WTERMSIG(status));
                } else if (WIFSTOPPED(status)) { //Para cuando se para un proceso. Al usar wait() en vez de waitpid() no nos sirve.
                    printf("Proceso Padre, Hijo con PID %ld parado al recibir la señal %d\n", (long int)flag,WSTOPSIG(status));
                } else if (WIFCONTINUED(status)){ //Para cuando se reanuda un proceso parado. Al usar wait() en vez de waitpid() no nos sirve.
                    printf("Proceso Padre, Hijo con PID %ld reanudado\n",(long int) flag);		  
                }	
            }
            if (flag==(pid_t)-1 && errno==ECHILD)
            {
                printf("Proceso Padre, valor de errno = %d, definido como %s, no hay más hijos que esperar!\n", errno, strerror(errno));
            }
            else
            {
                printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
                exit(EXIT_FAILURE);
            }
            
            exit(EXIT_SUCCESS);	
        }//switch		 
}


int esPrimo(int numero){
    int result;
    int i;
    printf("Estoy en primos\n");
    printf("%i\n", numero);
    for(i=1; i <=numero; i++){
        if(numero%i==0){
            result++;
        }
    }

    if(result == 2){
        return 1;
    }
    else{
        return 0;
    }

}