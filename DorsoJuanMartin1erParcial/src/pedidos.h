/*
 * pedidos.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define CANT_CARACTERES 51
#define CANT_REINTENTOS 2
#define CANT_PEDIDOS 1000
#define CANT_MAX_KG 10000
#define ESTADO_COMPLETADO 1
#define ESTADO_PENDIENTE 2

typedef struct
{
	int id;
	int status;
	//***************
	int idCliente;
	float cantKg;
	int estado;
	float cantKgHDPE;
	float cantKgLDPE;
	float cantKgPP;

}sPedido;

static int generarIdPedido(void);

int initLugarLibrePedido(sPedido *aArray, int cantidad);
int altaPedidoPorId(sPedido *aArray, int cantidad,sPedido pedido);
int buscarLugarLibrePedido(sPedido *aArray, int cantidad);
int buscarPedidoPorId(sPedido *aArray, int cantidad,int id);
int altaUnSoloPedidoPorUI(sPedido *pedido,sCliente *aCliente,int cantCliente);
int imprimirArrayPedidosStatusOk(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int procesarResiduosPorID(sPedido *aArray,int cantidad,int id);
int imprimirArrayPedidosStatusOkyPendientes(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int imprimirArrayPedidosStatusOkyCompletados(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);


#endif /* PEDIDOS_H_ */
