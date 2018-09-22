#include <stdio.h>
#include <stdlib.h>

void esta_dentro(char *cadena, char caracter, int *cantidad, int *contador){
	while(*contador<20){
		if (cadena[*contador]==caracter){
			*cantidad += 1;
		}
		*contador += 1;
	}
}


int main(int argc, char const *argv[])
{
	char* cadena;
	char caracter[1];
	int cantidad=0;
	int contador=0;
	
	cadena = (char*) calloc(20, sizeof(char));

	if (cadena == NULL){
		printf("Error con la asignación de memoria\n");
		exit(-1);
	}

	printf("Introduzca la cadena de texto\n");
	scanf("%s", cadena); //Al hacerlo con scanf los espcios no los coge

	printf("Introduzca el caracter a buscar\n");
	scanf("%s", caracter);

	esta_dentro(cadena, *caracter, &cantidad, &contador);

	printf("%d\n", cantidad);

	free(cadena);


	return 0;
}