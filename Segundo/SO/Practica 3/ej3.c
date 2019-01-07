//José Márquez Doblas GG2 Ingeniría Informática
#include <stdio.h>
#include <string.h>

#define NPROC 5
#define QUANTUM 3
typedef struct params
{
    char nombre[10];
    int t_ejec;  // Se introducen
    int t_lleg;  
    int t_com;   // Se calculan
    int t_fin;
    int t_ret;
    int t_esp;
    int t_procesed;
    
} parametros;

void main(){
    
    int i, j;
    
    // Inicialización de los datos de procesos
    parametros procesos[NPROC];    
    strcpy(procesos[0].nombre, "A");
    procesos[0].t_ejec = 8;
    procesos[0].t_lleg = 0;
    procesos[0].t_procesed = 0;

    strcpy(procesos[1].nombre, "B");
    procesos[1].t_ejec = 4;
    procesos[1].t_lleg = 1;
    procesos[1].t_procesed = 0;

    strcpy(procesos[2].nombre, "C");
    procesos[2].t_ejec = 9;
    procesos[2].t_lleg = 2;
    procesos[2].t_procesed = 0;

    strcpy(procesos[3].nombre, "D");
    procesos[3].t_ejec = 5;
    procesos[3].t_lleg = 3;
    procesos[3].t_procesed = 0;

    strcpy(procesos[4].nombre, "E");
    procesos[4].t_ejec = 2;
    procesos[4].t_lleg = 4;
    procesos[4].t_procesed = 0;
    
    int min = 100000;
    int elmin = 0;
    int listos[NPROC];
    int pointer = 0;
    int procesando;
    int turno = 0;
    int quanto = QUANTUM;

    //Ponemos a 8 la cola de listos (0 es un proceso)
    for (i=0; i< NPROC; i++){
        listos[i] = 8;
    }
    
    for (i=0; i<100; i++){ //Le doy 100 unidades de procesado
        //Vemos que procesos nuevos llegan a la cola
        for(j=0; j<NPROC; j++){
            if(procesos[j].t_lleg == i){
                listos[pointer] = j; 
                pointer++;
            }
        }

        //Cada vez que se completa un Quantum cambiamos de proceso
        if (quanto == QUANTUM){
            procesando = listos[turno%NPROC];
            while(procesando == 8){ // Evitamos los procesos terminados
                turno += 1;
                procesando = listos[turno%NPROC];
            }
            turno += 1;
            quanto = 0;
        }

        //Apuntamos si es el comienzo
        if (procesos[procesando].t_procesed == 0) procesos[procesando].t_com = i;

        //Procesamos
        printf("El proceso %i va a ser ejecutado\n", procesando);
        procesos[procesando].t_procesed += 1;
        quanto += 1;

        //Comprobamos si se ha terminado ese proceso
        if (procesos[procesando].t_procesed == procesos[procesando].t_ejec){
            printf("Proceso %i terminado\n", procesando);
            procesos[procesando].t_fin = i+1;
            if (procesando == 2) break; //Sabemos que el ultimo será el 2(C)
            //Eliminamos el proceso terminado de la cola
            for (j=0; j<NPROC; j++){
                if (procesando == listos[j]) listos[j] = 8;
            }
            //Reseteamos QUANTUM
            quanto = QUANTUM;
        } 
    
    }

    //Mostramos el resultado
    printf("\nProceso | t_comienzo | t_final | t_retorno | t_espera\n");
    printf("-------------------------------------------------------\n");
    for(i=0; i< NPROC; i++)
    {
        procesos[i].t_ret = procesos[i].t_fin - procesos[i].t_lleg;
        procesos[i].t_esp = procesos[i].t_ret - procesos[i].t_ejec;

        printf("   %s \t    %d \t\t %d \t   %d \t      %d\n", procesos[i].nombre,procesos[i].t_com, procesos[i].t_fin, procesos[i].t_ret, procesos[i].t_esp);
    }
    
    
}