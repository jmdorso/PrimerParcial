/*
 * pedidos.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include "pedidos.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


/** \brief va generando un ID secuencial cada vez que es llamada
 * \param void, no recibe ningun paramentro.
 * \return el id incrementado cada vez que es llamada(debido a que esta declarada como static
 * no pierde el valor anterior)
 *
 */

static int generarIdPedido(void)
{
	static int idIncremental=0;
	idIncremental++;

	return idIncremental;
}

/** \brief Inicializa un array de pedidos con el estado libre(es decir, un array vacio y listo para cargar)
 * \param *aArray es el array a inicializar
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int initLugarLibrePedido(sPedido *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int i;

	if(aArray != NULL && cantidad >0)
	{
		for(i=0;i<cantidad;i++)
		{
			aArray[i].status = STATUS_EMPTY;
		}
	retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Da de alta un pedido (previamente cargado) en el array (en la primer posicion libre que encuentra)
 * \param *aArray es el array en el que se dara de alta
 * \param cantidad es la cantidad de elementos del array
 * \param pedido es una variable con los datos del pedido a dar de alta dentro del array
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int altaPedidoPorId(sPedido *aArray, int cantidad,sPedido pedido)
{
	int retorno = EXIT_ERROR;
	int posArray;

	if(aArray != NULL && cantidad >0)
	{
		posArray = buscarLugarLibrePedido(aArray,cantidad);
		if(posArray >= 0 && buscarPedidoPorId(aArray,cantidad,pedido.id) == -1)
			{
				pedido.status=STATUS_NOT_EMPTY;
				pedido.estado=ESTADO_PENDIENTE;
				pedido.id=generarIdPedido();
				aArray[posArray] = pedido;
				retorno = EXIT_SUCCESS;
			}
	}
	return retorno;
}

/** \brief busca el primer lugar libre en el array
 * \param *aArray es el array de pedidos
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o la POSICION EN EL ARRAY del primer elemento libre
 *
 */

int buscarLugarLibrePedido(sPedido *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int posArray;

	if(aArray != NULL && cantidad >0)
	{
		for(posArray=0;posArray<cantidad;posArray++)
		{
			if(aArray[posArray].status == STATUS_EMPTY)
			{
				retorno = posArray;
				break;
			}
		}
	}
	return retorno;
}

/** \brief busca el elemento con el ID indicado en el array
 * \param *aArray es el array en el que se buscara el ID
 * \param cantidad es la cantidad de elementos del array
 * \param id es el ID a buscar
 * \return -1 si hay algun error o la POSICION EN EL ARRAY del elemento con dicho ID
 *
 */

int buscarPedidoPorId(sPedido *aArray, int cantidad,int id)
{
	int retorno = EXIT_ERROR;
	int posArray;

	if(aArray != NULL && cantidad >0 && id >= 0)
	{
		for(posArray=0;posArray<cantidad;posArray++)
		{
			if(aArray[posArray].status == 1)
			{
				if(aArray[posArray].id == id)
				{
				retorno = posArray;
				break;
				}
			}
		}
	}
	return retorno;
}

/** \brief cargamos datos de un pedido a traves de interaccion con el usuario
 * \param *pedido una variable del tipo pedido en donde cargar los datos
 * \param cliente el array de clientes en donde buscar la informacion
 * \param cantCliente el tamaño del array de clientes
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int altaUnSoloPedidoPorUI(sPedido *pedido,sCliente *aCliente,int cantCliente)
{
	int retorno = EXIT_ERROR;

	int bufferIdCliente;
	float cantKgAux;

	imprimirArrayClientesStatusOk(aCliente,CANT_CLIENTES);
	retorno = getInt(&bufferIdCliente,"Ingrese ID del cliente que realiza el pedido: ","\nError",1,CANT_CLIENTES,CANT_REINTENTOS);
	if(retorno == EXIT_SUCCESS)
	{
		if(buscarClientePorId(aCliente,cantCliente,bufferIdCliente)>=0)
		{
			if(getValidFloatFromString(&cantKgAux,"\nIngrese cant. total de Kg de Residuos del cliente: ","\nError",0,CANT_MAX_KG,CANT_REINTENTOS)==EXIT_SUCCESS)
			{
				pedido->cantKg = cantKgAux;
				pedido->idCliente = bufferIdCliente;
				pedido->estado = ESTADO_PENDIENTE;
			}
			else
			{
				retorno=EXIT_ERROR;
			}
		}
		else
		{
			retorno=EXIT_ERROR;
		}

	}
	return retorno;
}

/** \brief imprime elementos del array con el campo status NOT EMPTY(es decir elementos cargados)
 * \param *aArray es el array a mostrar
 * \param cantidad es la cantidad de elementos del array
 * \param aClientes es el array de clientes a mostrar
 * \param cantClientes es la cant de clientes
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int imprimirArrayPedidosStatusOk(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente)
{
	int i;
//	int auxId;
	int retorno = EXIT_ERROR;
	char estadoPedido[2][25] = {"Completado","Pendiente"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		printf("\n--------------------------------LISTA DE PEDIDOS--------------------------------\n");
		printf("%3s | %10s | %15s | %3s | %10s | %10s | %10s\n","ID","CANTKG","ESTADO","ID CLIENTE","KG HDPE","KG LDPE","KG PP");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY)
			{
				//auxId = buscarClientePorId(aCliente,cantCliente,aArray[i].idCliente);
				printf("%3.d | %10.2f | %15s | %10.d | %10.2f | %10.2f | %10.2f\n",
						aArray[i].id,aArray[i].cantKg,estadoPedido[aArray[i].estado-1],aArray[i].idCliente,aArray[i].cantKgHDPE,aArray[i].cantKgLDPE,aArray[i].cantKgPP);
			}
		}
	}
	return retorno;
}

/** \brief la funcion procesa los residuos en sus distintos tipos y busca por ID
 * \param *aArray es el array de pedidos
 * \param cantidad es la cantidad de elementos del array
 * \param id es el ID a buscar
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int procesarResiduosPorID(sPedido *aArray,int cantidad,int id)
{
	int retorno = EXIT_ERROR;
	int posArray;
	float bufferHdpe;
	float bufferLdpe;
	float bufferPp;
	float sumaKg;
	float restoResiduo;
	sPedido auxPedido;

	if(aArray != NULL && cantidad>0 && id>=0)
	{
		posArray = buscarPedidoPorId(aArray,cantidad,id);
		if(posArray != -1)
		{
			auxPedido = aArray[posArray];
			if(auxPedido.estado != ESTADO_COMPLETADO)
			{
				printf("\n\nClasificacion de residuos: Ingrese KG de cada tipo (no sobrepasar el total [%.2f Kg]\n\n",auxPedido.cantKg);
				getValidFloatFromString(&bufferHdpe,"Ingrese cant. KG de residuos HDPE: \n",
						"\nError!",0,CANT_MAX_KG,CANT_REINTENTOS);
				getValidFloatFromString(&bufferLdpe,"Ingrese cant. KG de residuos LDPE: \n",
									"\nError!",0,CANT_MAX_KG,CANT_REINTENTOS);
				getValidFloatFromString(&bufferPp,"Ingrese cant. KG de residuos PP: \n",
									"\nError!",0,CANT_MAX_KG,CANT_REINTENTOS);
				sumaKg = bufferHdpe+bufferLdpe+bufferPp;
				if(sumaKg <= auxPedido.cantKg)
				{
					auxPedido.cantKgHDPE = bufferHdpe;
					auxPedido.cantKgLDPE = bufferLdpe;
					auxPedido.cantKgPP = bufferPp;
					auxPedido.estado = ESTADO_COMPLETADO;
					aArray[posArray]=auxPedido;
					restoResiduo = auxPedido.cantKg - sumaKg;
					printf("\n\nCarga exitosa, le sobran %.2f Kg",restoResiduo);
					retorno=EXIT_SUCCESS;
				}
				else if(sumaKg > auxPedido.cantKg)
				{
					printf("\nError, sobrepaso el total de KG");
				}
			}
			else
			{
				printf("\n\nEl pedido ya se encuentra completado\n\n");
			}
		}
	}
	return retorno;
}

/** \brief imprime elementos del array con el campo status NOT EMPTY(es decir elementos cargados) y estado PENDIENTE
 * \param *aArray es el array a mostrar
 * \param cantidad es la cantidad de elementos del array
 * \param aClientes es el array de clientes a mostrar
 * \param cantClientes es la cant de clientes
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int imprimirArrayPedidosStatusOkyPendientes(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente)
{
	int i;
	int auxId;
	int retorno = EXIT_ERROR;
	char estadoPedido[2][25] = {"Completado","Pendiente"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		printf("\n-----------------------------LISTA DE PEDIDOS PENDIENTES--------------------------------\n");
		printf("%15s | %15s | %10s | %15s\n","CUIT","DIRECCION","CANTKG","ESTADO");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY && aArray[i].estado==ESTADO_PENDIENTE)
			{
				auxId = buscarClientePorId(aCliente,cantCliente,aArray[i].idCliente);
				printf("%15s | %15s | %10.2f | %15s\n",
						aCliente[auxId].cuit,aCliente[auxId].direccion,aArray[i].cantKg,estadoPedido[aArray[i].estado-1]);
			}
		}
	}
	return retorno;
}

/** \brief imprime elementos del array con el campo status NOT EMPTY(es decir elementos cargados) y estado COMPLETADO
 * \param *aArray es el array a mostrar
 * \param cantidad es la cantidad de elementos del array
 * \param aClientes es el array de clientes a mostrar
 * \param cantClientes es la cant de clientes
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int imprimirArrayPedidosStatusOkyCompletados(sPedido *aArray, int cantidad,sCliente *aCliente, int cantCliente)
{
	int i;
	int auxId;
	int retorno = EXIT_ERROR;
	char estadoPedido[2][25] = {"Completado","Pendiente"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		printf("\n-----------------------------LISTA DE PEDIDOS COMPLETADOS--------------------------------\n");
		printf("%15s | %15s | %10s | %10s | %10s | %15s\n","CUIT","DIRECCION","KG HDPE","KG LDPE","KG PP","ESTADO");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==STATUS_NOT_EMPTY && aArray[i].estado==ESTADO_COMPLETADO)
			{
				auxId = buscarClientePorId(aCliente,cantCliente,aArray[i].idCliente);
				printf("%15s | %15s | %10.2f | %10.2f | %10.2f | %15s\n",
						aCliente[auxId].cuit,aCliente[auxId].direccion,aArray[i].cantKgHDPE,aArray[i].cantKgLDPE,aArray[i].cantKgPP,estadoPedido[aArray[i].estado-1]);
			}
		}
	}
	return retorno;
}

/** \brief carga datos de prueba en el array
 * \param *aArray es el array de clientes
 * \param cantidad es la cantidad de elementos del array
 * \return VOID
 *
 */

int contadorDePedidosPendientePorCliente(sCliente *aArray,int cantidad,
										sPedido *aPedido,int cantPedido,
										auxContCliente *aContCliente,int cantContCliente)
{
	int retorno=EXIT_ERROR;
	int i;
	int j;

	if(aArray != NULL && cantidad>0 &&
		aPedido != NULL && cantPedido>0 &&
		aContCliente != NULL && cantContCliente>0)
	{
		printf("\n--------------------------------LISTA DE CLIENTES--------------------------------\n");
		printf("%3s | %15s | %15s | %15s | %15s | %15s\n","ID","NOMBRE","CUIT","LOCALIDAD","DIRECCION","PEDIDOS PENDIENTES");
		for(i=0;i<cantContCliente;i++)
		{
			aContCliente[i].status = STATUS_EMPTY;
			aContCliente[i].contPedidos = 0;
		}
		for(i=0;i<cantidad;i++)
		{
			aContCliente[i].idCliente=aArray[i].id;
			for(j=0;j<cantPedido;j++)
			{
				if((aArray[i].id == aPedido[j].idCliente) && (aPedido[j].estado==ESTADO_PENDIENTE))
				{
					aContCliente[i].contPedidos++;
					retorno=EXIT_SUCCESS;
				}
			}
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				printf("%3d | %15s | %15s | %15s | %15s | %5d\n",
				aArray[i].id,aArray[i].nombre,aArray[i].cuit,aArray[i].localidad,aArray[i].direccion,aContCliente[i].contPedidos);
			}

		}
	}
	return retorno;
}
