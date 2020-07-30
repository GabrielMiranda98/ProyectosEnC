#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "prestamo.h"
#include "utn.h"
#include "informes.h"


int main(void)
{setbuf(stdout,NULL);

				eCliente arrayCliente [QTY_CLIENTE];
				inicializarCliente (arrayCliente,QTY_CLIENTE);
				inicializarMonto(arrayCliente,QTY_CLIENTE);
				inicializarCuotas(arrayCliente,QTY_CLIENTE);
				inicializarCantidadDePrestamos(arrayCliente,QTY_CLIENTE);
				inicializarcPrestamoSaldado(arrayCliente,QTY_CLIENTE);
				inicializarcPrestamoActivo(arrayCliente,QTY_CLIENTE);

				ePrestamo arrayPrestamo [QTY_PRESTAMO];
				inicializarPrestamo(arrayPrestamo,QTY_PRESTAMO);
			hardcodeCliente (arrayCliente,QTY_CLIENTE,1,"Gabriel","Miranda","20-41308625-7",2,4,0,2);
			hardcodeCliente (arrayCliente,QTY_CLIENTE,2,"LIL","SUPA","20-31458796-7", 1,1,1,0);
			hardcodeCliente (arrayCliente,QTY_CLIENTE,3,"CAN","SERBERO","20-31458796-7",3,4,1,2);

	 	int idCliente = 1;
	 	int idPrestamo = 1;
		int opcion = 0;
		int indice;
		hardcodePrestamo(arrayPrestamo,0,QTY_PRESTAMO,2,1,1,1500);

		while(opcion !=11)
		{
			utn_getUnsignedInt("\nMenu\n\n1-Alta de cliente\n2-Modificar datos de cliente\n3-Baja de cliente\n4-Pr�stamo\n5-Saldar pr�stamo\n6-Reanudar pr�stamo\n7-Imprimir Clientes\n8-Imprimir pr�stamos\n9-Informar clientes\n10-informar Prestamos\n11-SALIR\n Ingrese una opcion: ","\nError\n",1,sizeof(int),1,2,3,&opcion);

			switch(opcion)
			{
			case 1:
			if(	altaCliente(arrayCliente,QTY_CLIENTE,&idCliente)==0)
			{
				printf("\nALTA EXITOSA\n");
			}
			else
			{
				printf("\nALTA DENEGADA\n");
			}

				/*
				*1) Alta de cliente: Se da de alta un cliente con nombre, apellido, y c.u.i.l.
				*1) Se generar� un ID �nico para este cliente que se imprimir� por pantalla si el alta es correcta.
				*
				*/
				break;
			case 2:
				utn_getUnsignedInt("\nIngrese el ID del Cliente a modificar\n","\nError\n",1,sizeof(int),0,QTY_CLIENTE,3,&indice);
				modificarCliente(arrayCliente,QTY_CLIENTE,indice);
				/*
				 *2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitir� cambiar el nombre,
				 *2) el apellido y el c.u.i.l.
				*/

				break;
			case 3:
				utn_getUnsignedInt("\nIngrese el ID del Cliente a dar de baja\n","\nError\n",1,sizeof(int),0,QTY_CLIENTE,3,&indice);
				bajaCliente(arrayCliente,QTY_CLIENTE,indice,arrayPrestamo,QTY_PRESTAMO);
				/*
				 *3) Baja de cliente: Se ingresa el ID del cliente y se listar�n todos los pr�stamos de
				 *	dicho cliente. Luego se preguntar� si se quiere confirmar la eliminaci�n, la cual implicar� la eliminaci�n de todos los pr�stamos y del cliente.
				*/

				break;
			case 4:
				utn_getUnsignedInt("\nIngrese el ID del Cliente a entregar prestamo\n","\nError\n",1,sizeof(int),0,QTY_CLIENTE,3,&indice);
					if(altaPrestamo(arrayPrestamo,QTY_PRESTAMO,&idPrestamo,0,arrayCliente,QTY_CLIENTE,indice)==0)
					{printf("\nCarga de Prestamo Exitosa\n");}
					else
					{
						printf("\nERROR EN LA CARGA\n");
					}

				/*

				 *4) Pr�stamo: Permitir� crear un nuevo pr�stamo. Se pedir�n los siguientes datos: ID de cliente, importe, cantidad de cuotas.
				 * Se generar� autom�ticamente un identificador num�rico para el pr�stamo y se imprimir� en pantalla.
				*/

				break;
			case 5:
				utn_getUnsignedInt("\nIngrese el ID del Prestamo a saldar\n","\nError\n",1,sizeof(int),0,QTY_PRESTAMO,3,&indice);
				bajaPrestamo(arrayPrestamo,QTY_PRESTAMO,indice,arrayCliente,QTY_CLIENTE);
				/*
				 *5) Saldar pr�stamo: Se pedir� el ID del pr�stamo y se imprimir� la informaci�n del
				 * cliente al que pertenece, luego se pedir� confirmaci�n para cambiarse de estado
				 *  y se cambiar� al estado "saldado".
				*/

				break;
			case 6:
				utn_getUnsignedInt("\nIngrese el ID del Prestamo a renaudar\n","\nError\n",1,sizeof(int),0,QTY_PRESTAMO,3,&indice);
				modificarPrestamo(arrayPrestamo,QTY_PRESTAMO,indice,arrayCliente,QTY_CLIENTE);
				/*
				 *6) Reanudar pr�stamo: Se pedir� el ID del pr�stamo y se imprimir� la informaci�n del
				 * cliente al que pertenece, luego se pedir� confirmaci�n para cambiarse de estado y se cambiar� al estado "activo".
				 *
				*/

				break;
			case 7:
				if(imprimirCliente(arrayCliente,QTY_CLIENTE)==0)
							{
								printf("\n \n");
							}
							else
							{
								printf("\n[NO EXISTEN PRESTAMOS CARGADOS]\n");
							}
				/*
				 *7) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de pr�stamos activos que posee.
				*/

				break;
			case 8:

				if(imprimirPrestamo(arrayPrestamo,QTY_PRESTAMO,arrayCliente,QTY_CLIENTE)==0)
				{
					printf("\n \n");
				}
				else
				{
					printf("\n[NO EXISTEN PRESTAMOS CARGADOS]\n");
				}

					/*
				 *8) Imprimir pr�stamos: Se imprimir� una lista de pr�stamo
				 *8)  activos con todos sus datos junto con el c.u.i.l. del cliente correspondiente.
				*/

				break;

			case 9:
				informarClientesPrestamos(arrayCliente,QTY_CLIENTE);

				/*
				 * 9) Informar clientes:
				 * a) Cliente con m�s pr�stamos activos.
				 * b) Cliente con m�s pr�stamos saldados

				*/
				break;
			case 10:
				informarPrestamos(arrayPrestamo,QTY_PRESTAMO);
				/*
				 *	10) Informar pr�stamos:
				 *	a) Cantidad de pr�stamos de importe mayor a 1000: Se ingresar� el importe y se imprimir� la cantidad de pr�stamos activos con ese importe.
				 *
				*/
				break;
			}
			/*
			 * Nota 0: El sistema soportar� una capacidad m�xima de 50 clientes y 50 pr�stamos
			 * Nota 1: Se deber�n desarrollar bibliotecas por cada entidad las cuales contendr�n las funciones (Alta, Baja,
			 * Modificar, etc.). Los informes deber�n estar en una biblioteca aparte.
			 * Nota 2: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar lasreglas de estilo de la c�tedra.
			 *
			*/
		}
		return 0;
}
