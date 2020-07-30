/*
 ============================================================================
 Name        : ParcialCine_00.c
 Author      : Gabriel Miranda
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Movies.h"

int main()
{
	setbuf(stdout,NULL);
	int exit = 1;
	char auxiliarArchivo[50];
   LinkedList* listaCine = ll_newLinkedList();

    do{

        switch(controller_menu())
        {
				case 1:
				    utn_getArchivo("\nIngrese el nombre del archivo\n","\nError\n",0,10,3,auxiliarArchivo);
				    if(controller_loadFromText(auxiliarArchivo,listaCine)==-1)
				    {
				    	printf("\nError con el nombre del archivo\n");
				    }

					break;
				case 2:
					controller_ListMovies(listaCine);
					break;
				case 3:

					if(controller_mapMovie(listaCine)==0)
					{
					controller_saveAsTextMontoFacturado("data_monto_facturado.csv",listaCine);
					}
					else
					{
						printf("\nError\n");
					}
					break;
				case 4:
					controller_filterMovies(listaCine);
					break;
				case 5:
					  exit = 0;
					  printf("\nFin de programa\n");
					  break;
        }
    }while(exit!=0);
    return 0;
}
