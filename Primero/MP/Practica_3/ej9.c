#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* libros;
	char nombre[50];
	int conteo = 0;
	if ((libros=fopen("libros_ej9.txt", "r"))==NULL){
		printf("Error al abrir el archivo de libros\n");
		exit(-1);
	}

	while(fgets(nombre, 50, libros)!= NULL){
		conteo = conteo + 1;
	}

	conteo = conteo/4;
	printf("Hay %i libros diferentes\n", conteo);
	fclose(libros);
	return 0;
}