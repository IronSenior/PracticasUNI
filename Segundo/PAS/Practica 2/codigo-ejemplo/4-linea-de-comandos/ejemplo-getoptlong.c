/*
Ejemplo extraído y adaptado del estándar POSIX y glibc.
Enlace a la página de documentación de la implemencación de getopt de glibc:
http://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Options.html
http://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Option-Example.html
*/

/*
./a.out
./a.out -d hola
./a.out --delete
./a.out -k
./a.out k ----(Que observas en este caso)?----
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main (int argc, char **argv)
{
	int c;
	
	/* Estructura a utilizar por getoptlong */
	static struct option long_options[] =
	{
		/* Opciones que no van a actuar sobre un flag */
		/* "opcion", recibe o no un argumento, 0,
		   identificador de la opción */
		{"add",	 no_argument,	   0, 'a'},
		{"block",  no_argument,	   0, 'b'},
		{"delete",  required_argument, 0, 'd'},
		{"create",  required_argument, 0, 'c'},
		{"file",	required_argument, 0, 'f'},
		/* Necesario para indicar el final de las opciones */
		{0, 0, 0, 0}
	};

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	int aflag = 0;
	int bflag = 0;
	char *cvalue = NULL;
	char *dvalue = NULL;
	char *fvalue = NULL;

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;
	
	/* Deshabilitar la impresión de errores por defecto */
	/* opterr=0; */
	while ((c = getopt_long (argc, argv, "abc:d:f:", long_options, &option_index))!=-1)
	{
		/* El usuario ha terminado de introducir opciones */
		if (c == -1)
			break;
		switch (c)
		{
			case 'a':
				//printf("Opción -a\n");
				aflag=1;
				break;

			case 'b':
				//printf("Opción -b\n");
				bflag=1;
				break;

			case 'c':
				//printf("Opción -c con valor '%s'\n", optarg);
				cvalue = optarg;
				break;

			case 'd':
				//printf("Opción -d con valor '%s'\n", optarg);
				dvalue = optarg;
				break;

			case 'f':
				//printf("Opción -f con valor '%s'\n", optarg);
				fvalue = optarg;
				break;

			case '?':
				/* getopt_long ya imprime su mensaje de error, no es necesario hacer nada */
				/* Si queremos imprimir nuestros propios errores, debemos poner opterr=0,
				 y hacer algo como lo que se expone a continuacion. Pruebe a hacer sus propios errores.
				if (optopt == 'c')
					fprintf (stderr, "La opción %c requiere un argumento.\n", optopt);*/
				break;

			default:
				abort ();
		}
		printf("optind: %d, optarg: %s, optopt: %c\n", optind, optarg, optopt);
	}

	/* Imprimir el resto de argumentos de la línea de comandos que no son opciones con "-" */
	if (optind < argc)
	{
		printf("Argumentos ARGV que no son opciones: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		putchar ('\n');
	}
	printf ("aflag = %d, bflag = %d, cvalue = %s, dvalue = %s, fvalue = %s\n",aflag, bflag, cvalue, dvalue, fvalue);

	exit (0);
}

