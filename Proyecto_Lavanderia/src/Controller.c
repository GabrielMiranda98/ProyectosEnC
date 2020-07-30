#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Articulo.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
int controller_menu()
{
    int option = -1;
        printf("\n\t -Repaso Parcial N 2: LinkedList- \n\t\tGabriel Miranda \n\n");
        printf("1. Cargar archivo\n");
        printf("2. Ordenar\n");
        printf("3. Imprimir\n");
        printf("4. Mapeo \n");
        printf("5. Guardar mapeo \n");
        printf("6. Informe \n");
        printf("7. Salir. \n");
        utn_getNumero(&option,"\nIngrese una opcion:\n"
        	    			,"\nERROR ingrese una opcion valida\n",1,7,3);
        return option;
}

int controller_loadFromText(char* path , LinkedList* pArrayListPrototipo)
{
		int retorno = -1;
	    int crear = 2;
	    FILE* listaFT;
	    if((listaFT=fopen(path, "r+")) == NULL)
	    {
	        printf("No se ha encontrado el archivo. ");
	        utn_getNumero(&crear,"\nDesea crear un archivo?  1-Si 2-No\n","\nError, opcion no valida\n",1,2,3);
	        if(crear == 1)
	        {
	            if ((listaFT=fopen(path,"w+"))==NULL)
	            {
	                printf("Error, no se ha podido abrir el archivo.\n");
	            }
	            else
	            {
	                printf("Archivo creado. ");
	                retorno=0;
	            }
	        }
	        else
	        {
	          printf("Volviendo al menu\n");
	        }
	    }
	    else
	    {
	        parser_PrototipoFromText(listaFT, pArrayListPrototipo);
	        printf("Archivo encontrado y cargado. ");
	        retorno=0;
	    }
	    return retorno;
}

int controller_ListPrototipo(LinkedList* pArrayListPrototipo)
{
	    int retorno = -1;
	    int i;
	    int auxPrimerParametro=0,auxCuartoParametro=0,auxQuintoParametro=0;
	    char auxSegundoParametro[50],auxTercerParametro[50],auxDiasThis[50];
	    Articulo* auxP=NULL;
	    if((ll_len(pArrayListPrototipo))>0 &&pArrayListPrototipo!=NULL){
	        for(i=0; i<ll_len(pArrayListPrototipo); i++){
	            auxP = (Articulo*)ll_get(pArrayListPrototipo, i);


	            	prototipo_getPrimerParametro(auxP,&auxPrimerParametro);
			    	prototipo_getSegundoParametro(auxP,auxSegundoParametro);
			    	prototipo_getTercerParametro(auxP,auxTercerParametro);
			    	prototipo_getCuartoParametro(auxP,&auxCuartoParametro);
			    	prototipo_getQuintoParametro(auxP,&auxQuintoParametro);
			    	switch(auxQuintoParametro)
				    				   {
						case 1:
				    				   		   strcpy(auxDiasThis,"CUIDADO DE ROPA");
				    				   		   break;
				    				   	   case 2:
				    				   		   strcpy(auxDiasThis,"LIMPIEZA Y DESINFECCION");
				    				   		   break;
				    				   	   case 3:
				    				   		   strcpy(auxDiasThis,"CUIDADO PERSONAL E HIGIENE");
				    				   		   break;
				    				   	   case 4:
				    				   		   strcpy(auxDiasThis,"CUIDADO DEL AUTOMOTOR");
				    				   		   break;

				    				  }
	            if(auxP != NULL)
	            {	retorno=0;
	            	printf("\nID:[%d]\nARTICULO: [%s]\nMEDIDA [%s] \nPRECIO: [%d] \nRUBRO ID: [%s] \n", auxPrimerParametro,auxSegundoParametro,auxTercerParametro,auxCuartoParametro,auxDiasThis);
	            }
	        }
	    }else{
	    	printf("\nNO HAY NADA PARA MOSTRAR\n");
	    }
	    return retorno;

}

void controller_sortPrototipo(LinkedList* pArrayListPrototipo)
{
        ll_sort(pArrayListPrototipo, ArticuloSortByName, 1);
        printf("Ordenamiento por articulo realizado!\n");
}

int controller_mapPrototipos(LinkedList* pArrayListPrototipo)
{
    int retorno = -1;

    if(ll_map(pArrayListPrototipo, prototipo_map) == 0){
    	printf("Descuentos realizados");
      	retorno=0;
    }
    return retorno;
}

int controller_saveAsTextModificacion(char* path , LinkedList* pArrayListPrototipo)
{
	 	int retorno = -1;
	    int auxIdThis,auxPrecioThis,auxRubroThis;
	    char auxArtThis[50],auxMedidaThis[50];

	    Articulo* auxP;

	    FILE* lista = fopen("mapeado.csv", "w");


	    if(lista==NULL){
	        printf("Error para guardar\n");
	        retorno=-1;
	    }

	    fprintf(lista, "id,articulo,medida,precio con descuento,rubro\n");
	        	if(pArrayListPrototipo!=NULL)
	        	{
	        	        for(int i=0; i<ll_len(pArrayListPrototipo); i++){
	        	        	auxP = (Articulo*)ll_get(pArrayListPrototipo, i);

	        	          prototipo_getPrimerParametro(auxP,&auxIdThis);
	        	          prototipo_getSegundoParametro(auxP,auxArtThis);
	        	          prototipo_getTercerParametro(auxP,auxMedidaThis);
	        	          prototipo_getCuartoParametro(auxP,&auxPrecioThis);
	        	          prototipo_getQuintoParametro(auxP,&auxRubroThis);

	        	            fprintf(lista, "%d,%s,%s,%d,%d\n",auxIdThis,auxArtThis
	        	            		,auxMedidaThis,auxPrecioThis,auxRubroThis);

	        	        }
	        printf("Archivo Guardado.\n");
	        retorno = 1;
	    }


        fclose(lista);
	    return retorno;
	    }

int controller_makeInfo(LinkedList* pArrayListProductos)
{
   int retorno = 0;
   int mayoresA100, ventasDescripcion;
   printf("\n*************************\n Informe de ventas\n*************************\n");
   mayoresA100 = ll_count(pArrayListProductos, prototipoMayora100);
   if(mayoresA100 == -1){
       printf("No se ha podido hacer el conteo mayor a 100.");
       retorno = -1;
   }else{printf("Cantidad de unidades con precio mayor a 100: %d\n", mayoresA100);}

   ventasDescripcion = ll_count(pArrayListProductos, PrototipoMayorCantidadRubro);
   if(ventasDescripcion == -1)
   {printf("No se ha podido hacer el conteo de venta del rubro 1.");
   	retorno = -1;}
   else{printf("Cantidad de articulos del rubro 'CUIDADO DE ROPA'(1) vendidos: %d\n", ventasDescripcion);}
   return retorno;
}
