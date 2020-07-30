#include <stdio.h>
#include <stdlib.h>
#include "Articulo.h"
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"


int main()
{
	setbuf(stdout,NULL);
	int exit = 1;
	char archivo[50];
   LinkedList* listaPrototipo = ll_newLinkedList();
    do{switch(controller_menu()){
				case 1:
				utn_getTexto("\nIngrese el nombre del archivo junto .csv \n","\nError\n",0,40,4,archivo);
				if(controller_loadFromText(archivo,listaPrototipo)==-1)
				  {printf("\nError con el nombre del archivo\n");}
					break;
				case 2:
					controller_sortPrototipo(listaPrototipo);
					break;
				case 3:
					controller_ListPrototipo(listaPrototipo);
					break;
				case 4:
					controller_mapPrototipos(listaPrototipo);
					break;
				case 5:
				controller_saveAsTextModificacion("mapeado.csv",listaPrototipo);
					break;
				case 6:
					controller_makeInfo(listaPrototipo);
					break;
				case 7:
					  exit = 0;
					  printf("\nFin de programa\n");
					  break;
        }
    }while(exit!=0);
    return 0;
}
