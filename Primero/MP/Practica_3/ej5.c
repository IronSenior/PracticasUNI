#include <stdio.h>
#include <stdlib.h>

void suma(int*b num, int *contador, int *total){

	if (*contador < 10){
		*total += num[*contador]; //El fallo está aquí

		*contador += 1;

		return suma(num, contador, total);
	}
}

int main(int argc, char const *argv[]){

	int* numero;
	int contador = 0;
	int total = 0;
	numero = (int*) calloc(10, sizeof(int)); //Tiene que ser calloc para que inicialice a 0
	if (numero == NULL){
		printf("Error en la asignación de memoria\n");
		exit(-1);
	}

	printf("Introduzca el numero\n");
	scanf("%i", numero);

	suma(numero, &contador, &total);
	printf("%d\n", total);
	free(numero);
	return 0;

}