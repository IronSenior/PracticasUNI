#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void convertir_en_mayus(FILE* entrada){
	//He limitado ha 50 el tamaño de cada linea
	char linea[50];
	FILE* salida;
	if ((salida = fopen("mayusculas.txt", "w"))==NULL){ //Debe guardarlo con combre Mayusculas_nombredelfichero.txt  (Se hce con sprintf)
		printf("Error al crear el archivo\n");
		exit(-1);
	}

	//Va linea por linea y letra por letra convirtiendo en mayuscula
	while(fgets(linea, 50, entrada)!= NULL){
		for(int i=0; i<50; i++){
			linea[i] = toupper(linea[i]);
		}
		fprintf(salida, linea);
	}
	fclose(salida);
}

int main(int argc, char const *argv[]){

	//El usuario introducirá el nombre del fichero
	char* fichero; 
	printf("Introduzca el nombre del fichero\n");
	scanf("%s", fichero);

	//Abrimos el fichero de texto
	FILE* entrada;
	if ((entrada = fopen(fichero, "r"))==NULL){
		printf("Error al cagarse el archivo\n");
		exit(-1);
	}

	//Convierte en mayusculas el contenido del fichero
	convertir_en_mayus(entrada);
	printf("Su archivo ha sido creado\n");

	fclose(entrada);

	
	return 0;
}