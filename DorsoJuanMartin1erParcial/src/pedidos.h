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
#define KG_HDPE 1
#define KG_LDPE 2
#define KG_PP 3

#include "utn.h"
#include "cliente.h"

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

struct
{
	int status;
	//***************
	int idCliente;
	int contPedidos;
	float acum;
}typedef auxContCliente;

//static int generarIdPedido(void);

int initLugarLibrePedido(sPedido *aArray, int cantidad);
int altaPedidoPorId(sPedido *aArray, int cantidad,sPedido pedido);
int buscarLugarLibrePedido(sPedido *aArray, int cantidad);
int buscarPedidoPorId(sPedido *aArray, int cantidad,int id);
int altaUnSoloPedidoPorUI(sPedido *pedido,sCliente *aCliente,int cantCliente);
int imprimirArrayPedidos(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int imprimirArrayPedidosStatusOk(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int procesarResiduosPorID(sPedido *aArray,int cantidad,int id);
int imprimirArrayPedidosStatusOkyPendientes(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int imprimirArrayPedidosStatusOkyCompletados(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int contadorDePedidosPendientePorCliente(sCliente *aArray,int cantidad,
										sPedido *aPedido,int cantPedido,
										auxContCliente *aContCliente,int cantContCliente);
int bajaClienteYSusPedidosPorId(sCliente *aArray, int cantidad,int id,sPedido *aPedidos,int cantPedidos);
void altaForzadaPedido(sPedido *aArray,int cantidad);

#endif /* PEDIDOS_H_ */

