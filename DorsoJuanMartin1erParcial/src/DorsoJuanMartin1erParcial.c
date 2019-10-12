/*
 ============================================================================
 Name        : DorsoJuanMartin1erParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"

#define ALTA_OK 1
#define ALTA_DNS 0

int main(void)
{
	char seguir = 's';
	char salir;
	char confirmarBaja;
	char confirmarModif;
	sCliente unClienteAlta;
	sCliente unClienteBaja;
	sCliente unClienteModif;
	sCliente aClientes[CANT_CLIENTES];
	sPedido unPedidoAlta;
	sPedido unPedidoModif;
	sPedido aPedidos[CANT_PEDIDOS];
	int opcion;
	int flagAlta=ALTA_DNS;
	int flagAltaPedido=ALTA_DNS;
	int auxId;
	int id;

	initLugarLibreCliente(aClientes,CANT_CLIENTES);
	imprimirArrayClientes(aClientes,5);

	do{
		printf("----------------------------------------------------------------------------------\n");
	    printf("\tPrimer parcial 2019. Empresa de recoleccion || Juan Martin Dorso\n\n");
	    printf("01. Alta de cliente\n");
	    printf("02. Modificar datos de cliente\n");
	    printf("03. Baja de cliente\n");
	    printf("04. Crear pedido de recoleecion\n");
	    printf("05. Procesar residuos\n");
	    printf("06. Imprimir clientes\n");
	    printf("07. Imprimr pedidos pendientes\n");
	    printf("08. Imprimir pedidos precoesados\n");
	    printf("09. Salir\n\n");

	    if(getValidIntFromString(&opcion,"\tIngrese opcion: ","\nError",1,9,CANT_REINTENTOS)==0)
	    {
	    	switch(opcion)
	    	{
	    	case 1:
				if(altaUnSoloClientePorUI(&unClienteAlta)==EXIT_SUCCESS)
				{
					auxId=altaClientePorId(aClientes,CANT_CLIENTES,unClienteAlta);
					if(auxId>EXIT_SUCCESS)
					{
	    				flagAlta=ALTA_OK;
	    				printf("\n\nSe ingreso el cliente con ID: # %d\n\n",auxId);
					}
				}
	    		break;
	    	case 2:
				if(flagAlta == ALTA_DNS)
				{
					printf("\nERROR. Falta ingresar al menos un cliente.\n\n");
					break;
				}
				imprimirArrayClientesStatusOk(aClientes,CANT_CLIENTES);
				getValidIntFromString(&auxId,"\nIngrese el ID: ","\nError\n",1,CANT_CLIENTES,CANT_REINTENTOS);
				unClienteModif.id = auxId;
				auxId = buscarClientePorId(aClientes,CANT_CLIENTES,unClienteModif.id);
				if(aClientes[auxId].status== STATUS_NOT_EMPTY)
				{
					printf("Quiere Modificar el siguiente Cliente: \n");
					printf("Nombre: %s - CUIT: %s - ID: %d",aClientes[auxId].nombre,aClientes[auxId].cuit,aClientes[auxId].id);
					getChar(&confirmarModif,
							"\nSeguro desea modificar? Ingrese s (o cualquier tecla para continuar): ",
							"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
							'a',
							'z',
							CANT_REINTENTOS);
					if(confirmarModif == 's' || confirmarModif == 'S')
					{
						if(modificaClientePorId(aClientes,CANT_CLIENTES,unClienteModif.id)==EXIT_SUCCESS)
						{
							printf("\nMODIFICACION EXITOSA\n\n");
						}
						else
						{
							printf("\nERROR EN MODIFICACION\n\n");
						}
					}
				}
				else
				{
					printf("\n\nNo existe Cliente con ese ID\n\n");
				}
				break;
	    	case 3:
				if(flagAlta == ALTA_DNS)
				{
					printf("\nERROR. Falta ingresar al menos un cliente.\n\n");
					break;
				}
				imprimirArrayClientesStatusOk(aClientes,CANT_CLIENTES);
				getValidIntFromString(&auxId,"\nIngrese el ID: ","\nError\n",1,CANT_CLIENTES,CANT_REINTENTOS);
				unClienteBaja.id = auxId;
				auxId = buscarClientePorId(aClientes,CANT_CLIENTES,unClienteBaja.id);
				if(aClientes[auxId].status== STATUS_NOT_EMPTY)
				{
					printf("Quiere Eliminar el siguiente Cliente: \n");
					printf("Nombre: %s - CUIT: %s - ID: %d",aClientes[auxId].nombre,aClientes[auxId].cuit,aClientes[auxId].id);
					getChar(&confirmarBaja,
							"\nSeguro desea dar de baja? Ingrese s (o cualquier tecla para continuar): ",
							"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
							'a',
							'z',
							CANT_REINTENTOS);
					if(confirmarBaja == 's' || confirmarBaja == 'S')
					{
						if(bajaClientePorId(aClientes,CANT_CLIENTES,unClienteBaja.id)==EXIT_SUCCESS)
						{
							printf("\nBAJA EXITOSA\n\n");
						}
						else
						{
							printf("\nERROR EN BAJA\n\n");
						}
					}
				}
				else
				{
					printf("\n\nNo existe Cliente con ese ID\n\n");
				}
	    		break;
	    	case 4:
				if(altaUnSoloPedidoPorUI(&unPedidoAlta,aClientes,CANT_CLIENTES)==EXIT_SUCCESS)
				{
					if(altaPedidoPorId(aPedidos,CANT_PEDIDOS,unPedidoAlta)==EXIT_SUCCESS)
					{
	    				flagAltaPedido=ALTA_OK;
	    				printf("\n\nSe ingreso correctamente el pedido\n\n");
					}
				}
	    		break;
	    	case 5:
				if(flagAltaPedido == ALTA_DNS)
				{
					printf("\nERROR. Falta ingresar al menos un pedido.\n\n");
					break;
				}
				imprimirArrayPedidosStatusOk(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
				getValidIntFromString(&auxId,"\nIngrese el ID: ","\nError\n",1,CANT_PEDIDOS,CANT_REINTENTOS);
				unPedidoModif.id = auxId;
				auxId = buscarPedidoPorId(aPedidos,CANT_PEDIDOS,unPedidoModif.id);
				if(aPedidos[auxId].status== STATUS_NOT_EMPTY)
				{
					printf("Quiere Modificar el siguiente Pedido: \n");
					printf("ID: %d",aPedidos[auxId].id);
					getChar(&confirmarModif,
							"\nSeguro desea modificar? Ingrese s (o cualquier tecla para continuar): ",
							"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
							'a',
							'z',
							CANT_REINTENTOS);
					if(confirmarModif == 's' || confirmarModif == 'S')
					{
						if(procesarResiduosPorID(aPedidos,CANT_PEDIDOS,unPedidoModif.id)==EXIT_SUCCESS)
						{
							printf("\nMODIFICACION EXITOSA\n\n");
						}
						else
						{
							printf("\nERROR EN MODIFICACION\n\n");
						}
					}
				}
				else
				{
					printf("\n\nNo existe Pedido con ese ID\n\n");
				}
	    		imprimirArrayPedidosStatusOk(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
	    		break;
	    	case 6:
	    		break;
	    	case 7:
	    		imprimirArrayPedidosStatusOkyPendientes(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
	    		break;
	    	case 8:
	    		imprimirArrayPedidosStatusOkyCompletados(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
	    		break;
	    	case 9:
				getChar(&salir,
						"\nSeguro desea salir? Ingrese s (o cualquier tecla para continuar): ",
						"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
						'a',
						'z',
						CANT_REINTENTOS);
				if(salir == 's' || salir == 'S')
			     {
					printf("\n\n\tEl programa se cerrara.");
			        seguir = 'n';
			     }
	    		break;

	    	}
	    }

	}while(seguir=='s' || seguir=='S');

	return EXIT_SUCCESS;
}
