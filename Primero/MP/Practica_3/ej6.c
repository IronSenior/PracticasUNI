#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* entrada;
	if ((entrada = fopen(fichero, "r"))==NULL){
		printf("Error al abrir el archivo\n");
		exit(-1);
	}

	
	return 0;
}