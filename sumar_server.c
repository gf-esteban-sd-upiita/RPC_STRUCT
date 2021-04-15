// Código de implementación del procedimiento remoto.

#include "sumar.h"

// Se hace la definición del servicio correspondiente a la operación de suma.
int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */
	 
	// Se manda a imprimir un mensaje de verificación del recibimiento correcto de las peticiones del cliente por parte del servidor.
	printf("El procedimiento ha sido invocado remotamente.\n");
	// Se mandan a imprimir los parámetros que le fueron enviadas al servidor.
	printf("Parámetros: %d, %d.\n", argp->a, argp->b);
	// Se asigna a la variable 'result' el resultado de la operación artimética de la suma sobre los parámetros recibidos.
	result = argp->a + argp->b;
	printf("Devolviendo: %d.\n", result);
	// Se devuelve el resultado.
	return &result;
}
