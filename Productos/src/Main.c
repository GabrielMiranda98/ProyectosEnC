/*
 ============================================================================
 Name        : ParcialProductos_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 ID_Venta;Fecha_Venta;Codigo_Producto;Cantidad;Precio_Unitario;CUIT_Cliente
1;15/02/2020;MOUSE_432;94;8286.09;21-71848035-3
2;04/11/2019;MOUSE_598;75;13082.25;20-7409979-9
3;18/08/2019;TECLADO_245;6;13548.02;21-40641614-2
4;03/02/2020;LCD_TV;91;16830.85;20-50307730-9
5;14/01/2020;MOUSE_432;24;17458.5;20-88521570-5
6;22/07/2019;PARLANTEBL_23;49;13249.54;21-31945342-6
7;06/05/2020;MOUSE_598;95;28060.74;21-12410096-2
8;28/11/2019;PARLANTEBL_23;86;12758.59;20-23474520-6
9;23/08/2019;LED_TV;8;6187.81;21-41000476-1
10;09/07/2019;SMART_TV;23;15852.32;20-9361294-4



 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Productos.h"

int main(void)
{		setbuf(stdout,NULL);
		int exit = 1;
	   LinkedList* listaProductos = ll_newLinkedList();
	    do{switch(controller_menu())
		{			case 1:
					controller_loadFromText("data.csv",listaProductos);
							break;
					case 2:
						controller_makeInfo(listaProductos);
						break;
					case 3:
						  exit = 0;
						  printf("\nFin de programa\n");
						  break;
	       }
	    }while(exit!=0);
	    return 0;}
