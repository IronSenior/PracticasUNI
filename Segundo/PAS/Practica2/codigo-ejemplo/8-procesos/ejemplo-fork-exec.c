#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> //Control de errores
#include <string.h> //Para la funcion strerror(), que permite describir el valor de errno como cadena.

int main()
{
    pid_t rf, flag;
    int status;

    char *args[] = {"/bin/ls", "-t", "-l", (char *) 0 };  

    switch(rf=fork())
    {
		 case -1:
     		  printf ("Proceso Padre, no he podido crear el proceso hijo \n");
  	   	  exit(EXIT_FAILURE);
		 case 0 : // código que ejecuta el hijo
		     printf("Hijo %d ejecutando comando ls...\n",getpid()); 
		     execv("/bin/ls", args); //Reemplazo total del hijo por el proceso "ls"
		
		 //default: El padre no hace nada, directamente ya va a esperar a los hijos.
    }
    
 	/*Espera del padre a los hijos*/
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
		printf("Proceso Padre, valor de errno = %d, definido como: %s\n", errno, strerror(errno));
	}
	else
	{
		printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
		exit(EXIT_FAILURE);
	}		 
}
