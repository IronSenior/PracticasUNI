#include <stdio.h>
#include "funciones.h"

//Este archivo es solo para ver las ventajas del uso de punteros a Funciones 

int main(int argc, char const *argv[]){
	int elec;

	//Menú de selección para la función matemática
	printf("Elija funcion\n");
	printf("0 --> f(x)\n");
	printf("1 --> g(x)\n");
	printf("2 --> z(x)\n");
	scanf("%d", &elec);

	//Pide N al usuario
	int n = 0;
	printf("Introduzca el valor de N\n");
	scanf("%d", &n);

	
	//Resolución de la función
	if (elec == 0){
		//Ejecuta la función e imprime el resultado 
		for (float i=0; i<n; i+=0.2){
			float resultado = f(i);
			printf("El resultado para %f es %f\n", i, resultado);
		}
	}
	else{
		if (elec == 1){
			//Ejecuta la función e imprime el resultado 
			for (float i=0; i<n; i+=0.2){
				float resultado = g(i);
				printf("El resultado para %f es %f\n", i, resultado);
			}
		}
		else{
			//Ejecuta la función e imprime el resultado 
			for (float i=0; i<n; i+=0.2){
				float resultado = z(i);
				printf("El resultado para %f es %f\n", i, resultado);
			}
		}
	}

	return 0;
}
