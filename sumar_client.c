// Genera el cliente y hace la llamada al procedimiento remoto.

#include "sumar.h"
#include <stdio.h>

// Se define la función suma_prog_1, en la cual se hace la llamada a los procedimientos remotos.
void
suma_prog_1(char *host, int a, int b)
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	// Se hace la creación del cliente con la función clnt_create que tiene como argumentos la dirección del servidor, el nombre del programa remoto, el nombre de la versión y el protocolo de transporte, en este caso, UDP.
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	// Hace la asignación de los valores correspondientes de cada número recibido por la función suma_prog_1 a los argumentos del servicio de syma.
	suma_1_arg.a = a;
	suma_1_arg.b = b;

	// Asigna a result_1 el valor devuelto tras la llamada al servicio suma_1 cuyos argumentos son los elementos de la estructura.
	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	} else {
	// Imprime el resultado recibido del lado del cliente
		printf("Resultado: %d.\n", *result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	// Declaración de un puntero tipo char hacia la dirección del servidor así como de dos variables enteras a y b.
	char *host;
	int a, b;
	
	// Validación de los tres argumentos de la función suma_prog_1 como una cadena y dos enteros, respectivamente, para su posterior paso como parámetros en la llamada a dicha función.

	if (argc != 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	
	if((a = atoi(argv[2])) == 0 && *argv[2] != '0') {
		fprintf(stderr, "Valor inválido: %s.\n", argv[2]);
		exit(1);
	}
	
	if((b = atoi(argv[3])) == 0 && *argv[3] != '0') {
		fprintf(stderr, "Valor inválido: %s.\n", argv[3]);
		exit(1);
	}
	
	suma_prog_1 (host, a, b);
	
	// Declaración del estado de salida con el código 0 indicando la ejecución sin errores del programa.
exit (0);
}
