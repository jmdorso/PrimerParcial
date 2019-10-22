/*
 * informes.h
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "pedidos.h"


int clienteConMasPedidosPendientes(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int clienteConMasPedidosCompletados(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int clienteConMasPedidos(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int clienteConMasKgReciclados(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos);
int clienteConMenosKgReciclados(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos);
int imprimirArrayPedidosStatusOkyCompletadosMasMilKg(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int imprimirArrayPedidosStatusOkyCompletadosMenosCienKg(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int imprimirArrayPedidosStatusOkyCompletadosPorcentajeReciclado(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente);
int clienteConMasKgRecicladosVDos(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int clienteConMenosKgRecicladosVDos(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int clientesConMenosCienKgRecicladosVDos(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int clientesConMasMilKgRecicladosVDos(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente);
int cantPedidosPendientesPorLocalidad(sCliente *aCliente,int cantClientes,sPedido *aPedido,int cantPedidos,auxContCliente *aCont,int cantContCliente,char *localidad);

#endif /* INFORMES_H_ */
