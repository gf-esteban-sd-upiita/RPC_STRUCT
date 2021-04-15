// Código del stub del cliente, el cual contiene la implementación de la función sumar_1, serializa el parámetro, llama al procedimiento remoto y devuelve el resultado a través del procedimiento clnt_call.

#include <memory.h> /* for memset */
#include "sumar.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

int *
suma_1(dupla_int *argp, CLIENT *clnt)
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SUMA,
		(xdrproc_t) xdr_dupla_int, (caddr_t) argp,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
