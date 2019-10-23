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
#include "informes.h"

#define ALTA_OK 1
#define ALTA_DNS 0

int main(void)
{
	char seguir = 's';
	char salir;
	char confirmarBaja;
	char confirmarModif;
	char opcionInformar;
	sCliente unClienteAlta;
	sCliente unClienteBaja;
	sCliente unClienteModif;
	sCliente aClientes[CANT_CLIENTES];
	sPedido unPedidoAlta;
	sPedido unPedidoModif;
	sPedido aPedidos[CANT_PEDIDOS];
	auxContCliente aContClientePendiente[CANT_CLIENTES];
	auxContCliente aContClienteCompletado[CANT_CLIENTES];
	auxContCliente aContClienteTotal[CANT_CLIENTES];
	int opcion;
	int flagAltaPedido=ALTA_DNS;
	int auxId;
	//int id;
	int contClientes = 6;

	initLugarLibreCliente(aClientes,CANT_CLIENTES);
	initLugarLibrePedido(aPedidos,CANT_PEDIDOS);
	altaForzadaCliente(aClientes,CANT_CLIENTES);
	imprimirArrayClientesStatusOk(aClientes,CANT_CLIENTES);
	altaForzadaPedido(aPedidos,CANT_PEDIDOS);
	imprimirArrayPedidosStatusOk(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);

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
	    printf("09. Informes\n");
	    printf("10. Salir\n\n");

	    if(getValidIntFromString(&opcion,"\tIngrese opción: ","\nError",1,10,CANT_REINTENTOS)==0)
	    {
	    	switch(opcion)
	    	{
	    	case 1:
				if(altaUnSoloClientePorUI(&unClienteAlta,aClientes,CANT_CLIENTES)==EXIT_SUCCESS)
				{
					auxId=altaClientePorId(aClientes,CANT_CLIENTES,unClienteAlta);
					if(auxId>EXIT_SUCCESS)
					{
	    				contClientes++;
	    				printf("\n\nSe ingreso el cliente con ID: # %d\n\n",auxId);
	    			}
				}
	    		break;
	    	case 2:
				if(contClientes == 0)
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
							"\nSeguro desea modificar? Ingrese s (o cualquier tecla para cancelar modificación): ",
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
				if(contClientes == 0)
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
							"\nSeguro desea dar de baja? Ingrese s (o cualquier tecla para cancelar baja): ",
							"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
							'a',
							'z',
							CANT_REINTENTOS);
					if(confirmarBaja == 's' || confirmarBaja == 'S')
					{
						if(bajaClienteYSusPedidosPorId(aClientes,CANT_CLIENTES,unClienteBaja.id,aPedidos,CANT_PEDIDOS)==EXIT_SUCCESS)
						{
							contClientes--;
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
	    		if(contClientes == 0)
	    						{
	    							printf("\nERROR. Falta ingresar al menos un cliente.\n\n");
	    							break;
	    						}
				if(altaUnSoloPedidoPorUI(&unPedidoAlta,aClientes,CANT_CLIENTES)==EXIT_SUCCESS)
				{
					if(altaPedidoPorId(aPedidos,CANT_PEDIDOS,unPedidoAlta)==EXIT_SUCCESS)
					{
	    				printf("\n\nSe ingreso correctamente el pedido\n\n");
					}
				}
	    		break;
	    	case 5:
				imprimirArrayPedidosStatusOk(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
				getValidIntFromString(&auxId,"\nIngrese el ID del Pedido: ","\nError\n",1,CANT_PEDIDOS,CANT_REINTENTOS);
				unPedidoModif.id = auxId;
				auxId = buscarPedidoPorId(aPedidos,CANT_PEDIDOS,unPedidoModif.id);
				if(aPedidos[auxId].status== STATUS_NOT_EMPTY)
				{
					printf("\nQuiere Modificar el siguiente Pedido: \n");
					printf("ID del Pedido: %d\nCANT KG: %.2f\nID del cliente: %d\n",aPedidos[auxId].id,aPedidos[auxId].cantKg,aPedidos[auxId].idCliente);
					getChar(&confirmarModif,
							"\nSeguro desea modificar? Ingrese s (o cualquier tecla para cancelar modificacion): ",
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
	    		contadorDePedidosPendientePorCliente(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClientePendiente,CANT_CLIENTES);
	    		break;
	    	case 7:
	    		imprimirArrayPedidosStatusOkyPendientes(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
	    		break;
	    	case 8:
	    		imprimirArrayPedidosStatusOkyCompletados(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
	    		break;
	    	case 9:
	    		printf("\n\t\t||| A) Cliente con mas pedidos pendientes. |||\n");
	    		printf("\n\t\t||| B) Cliente con mas pedidos completados. |||\n");
	    		printf("\n\t\t||| C) Cliente con mas pedidos totales. |||\n");
	    		printf("\n\t\t||| D) Cliente que reciclo mas kilos. |||\n");
	    		printf("\n\t\t||| E) Cliente que reciclo menos kilos. |||\n");
	    		printf("\n\t\t||| F) Cantidad de Clientes que reciclaron mas de 1000 kilos. |||\n");
	    		printf("\n\t\t||| G) Cantidad de Clientes que reciclaron menos de 100 kilos. |||\n");
	    		printf("\n\t\t||| H) Imprimir  pedidos completados indicando PORCENTAJE de plastico reciclado. |||\n");
	    		printf("\n\t\t||| I) Ingresar una localidad e indicar cant. pedidos pendientes. |||\n");
	    		printf("\n\t\t||| J) Promedio de kilos de polipropileno reciclado en promedio por cliente. |||\n");
	    		printf("\n\t\t||| K) Obtener KG totales de un determinado tipo a traves del cuit. |||\n");
	    		printf("\n\t\t||| L) Volver atras. |||\n");
	    		if(getChar(&opcionInformar,"\nIngrese opcion(mayusculas): ","\nError!\n",'A','L',CANT_REINTENTOS)==0)
	    		{
	    			switch(opcionInformar)
	    			{
	    			case 'A':
	    	    		clienteConMasPedidosPendientes(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClientePendiente,CANT_CLIENTES);
	    				break;
	    			case 'B':
	    	    		clienteConMasPedidosCompletados(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteCompletado,CANT_CLIENTES);
	    				break;
	    			case 'C':
	    	    		clienteConMasPedidos(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteTotal,CANT_CLIENTES);
	    				break;
	    			case 'D':
	    	    		clienteConMasKgRecicladosVDos(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteTotal,CANT_CLIENTES);
	    				break;
	    			case 'E':
	    	    		clienteConMenosKgRecicladosVDos(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteTotal,CANT_CLIENTES);
	    				break;
	    			case 'F':
	    	    		clientesConMasMilKgRecicladosVDos(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteTotal,CANT_CLIENTES);
	    				break;
	    			case 'G':
	    	    		clientesConMenosCienKgRecicladosVDos(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteCompletado,CANT_CLIENTES);
	    				break;
	    			case 'H':
	    	    		imprimirArrayPedidosStatusOkyCompletadosPorcentajeReciclado(aPedidos,CANT_PEDIDOS,aClientes,CANT_CLIENTES);
	    				break;
	    			case 'I':
	    	    		cantPedidosPendientesPorLocalidad(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteCompletado,CANT_CLIENTES,"QUILMES");
	    				break;
	    			case 'J':
	    	    		clientePromKgPpReciclado(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,aContClienteCompletado,CANT_CLIENTES);
	    				break;
	    			case 'K':
  			    		kilosTotalesPorResiduosPorCuit(aClientes,CANT_CLIENTES,aPedidos,CANT_PEDIDOS,"30112233445",KG_LDPE);
	    				break;
	    			case 'L':
	    				break;
	    			}
	    		}
	    		printf("\n");
	    		break;
	    	case 10:
				getChar(&salir,
						"\nSeguro desea salir? Ingrese s (o cualquier tecla para continuar en el programa): ",
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
