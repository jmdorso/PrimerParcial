/*
 * cliente.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */



#ifndef CLIENTE_H_
#define CLIENTE_H_


#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define CANT_CARACTERES 51
#define CANT_CARACTERES_CUIT 15
#define CANT_REINTENTOS 2
#define CANT_CLIENTES 100

#include "utn.h"

typedef struct
{
	int id;
	int status;
	//***************
	char nombre[51];
	char direccion[51];
	char cuit[51];
	char localidad[51];

}sCliente;


//static int generarIdCliente(void);

int initLugarLibreCliente(sCliente *aArray, int cantidad);
int altaClientePorId(sCliente *aArray, int cantidad,sCliente cliente);
int buscarLugarLibreCliente(sCliente *aArray, int cantidad);
int buscarClientePorId(sCliente *aArray, int cantidad,int id);
int altaUnSoloClientePorUI(sCliente *cliente,sCliente *aArray,int cantidad);
int imprimirArrayClientes(sCliente *aArray, int cantidad);
int imprimirArrayClientesStatusOk(sCliente *aArray, int cantidad);
int modificaClientePorId(sCliente *aArray,int cantidad,int id);
void altaForzadaCliente(sCliente *aArray,int cantidad);
int buscarClientePorCuit(sCliente *aArray,int cantidad,char *cuit);

#endif /* CLIENTE_H_ */

