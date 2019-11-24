/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculator.h"


void
calculadora_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	operandos  suma_1_arg;
	int  *result_2;
	operandos  resta_1_arg;
	int  *result_3;
	operandos  multiplicacion_1_arg;
	int  *result_4;
	operandos  division_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = resta_1(&resta_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = multiplicacion_1(&multiplicacion_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = division_1(&division_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	calculadora_prog_1 (host);
exit (0);
}
