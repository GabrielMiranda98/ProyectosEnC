/*
 ============================================================================
 Name        : ParcialMyBook_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Prototipo.h"
#include "PrototipoTwo.h"


int main()
{
	setbuf(stdout,NULL);
	int exit = 1;
   LinkedList* listaPrototipo = ll_newLinkedList();
   LinkedList* listaPrototipoTwo = ll_newLinkedList();

    do{

        switch(controller_menu())
        {
				case 1:
				    if(controller_loadFromText("mensajes.csv",listaPrototipo)==-1)
				    {
				    	printf("\nError con el nombre del archivo\n");
				    }

					break;
				case 2:
					controller_ListPrototipo(listaPrototipo);
					break;
				case 3:
				    if(controller_loadFromTextTwo("usuarios.csv",listaPrototipoTwo)==-1)
				    {
				    	printf("\nError con el nombre del archivo\n");
				    }

					break;
				case 4:
					controller_ListPrototipoTwo(listaPrototipoTwo);
					break;
				case 5:
					controller_saveAsTextModificacion("feed.csv",listaPrototipo,listaPrototipoTwo);
					break;
				case 6:
					  exit = 0;
					  printf("\nFin de programa\n");
					  break;
        }
    }while(exit!=0);
    return 0;
}
