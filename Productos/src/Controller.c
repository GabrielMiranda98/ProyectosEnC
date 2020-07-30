#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Productos.h"
#include "utn.h"
int controller_menu()
{
    int option = -1;
        printf("\n\t -Repaso Parcial N 2: LinkedList- \n\t\tGabriel Miranda \n\n");
        printf("1. Cargar archivo data.csv (modo texto).- \n");
        printf("2. Generar archivo de informes.txt .-\n");
        printf("3. Salir. \n");
        utn_getNumero(&option,"\nIngrese una opcion:\n"
        	    			,"\nERROR ingrese una opcion valida\n",1,3,3);
        return option;
}

/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListMovies LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListProductos)
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
	        parser_ProductosFromText(listaFT, pArrayListProductos);
	        printf("Archivo encontrado y cargado. ");
	        retorno=0;
	    }
	    return retorno;
}

/** \brief Lista las ventas
 * \param pArrayListMovies LinkedList*
 * \return int
 */

int controller_ListProductos(LinkedList* pArrayListProductos)
{
	    int retorno = -1;
	    int i;
	    int auxIdThis=0,auxPrecioThis=0;
	    char auxFechaThis[50],auxCodigo[50], auxCantidadThis[50];
	    Productos* auxP=NULL;
	    if((ll_len(pArrayListProductos))>0 &&pArrayListProductos!=NULL){
	    	printf("\n\t\t\t\tTABLA CON DATOS DE VENTAS\t\t\n\n\n");
	    	printf("\tID\t\tNOMBRE PELICULA\t\tDIA\t\tHORARIO\t\tSALA\t\tCANTIDAD ENTRADAS\n");
	        for(i=0; i<ll_len(pArrayListProductos); i++){
	            auxP = (Productos*)ll_get(pArrayListProductos, i);


	            	producto_getId(auxP,&auxIdThis);
			    	producto_getFecha(auxP,auxFechaThis);
			    	producto_getCodigo(auxP,auxCodigo);
			    	producto_getCantidad(auxP,auxCantidadThis);
			    	producto_getPrecio(auxP,&auxPrecioThis);

	            if(auxP != NULL)
	            {	retorno=0;
	            	printf("%10d %19s %20s %20s %20d \n", auxIdThis,auxFechaThis,auxCodigo,auxCantidadThis,auxPrecioThis);
	            }
	        }
	    }else{
	    	printf("\nNO HAY VENTAS PARA MOSTRAR\n");
	    }
	    return retorno;

}
/** \brief Realiza un informe con lo pedido
 *
 * \param pArrayListEntity LinkedList*
 * \return int 0 si esta
 *
 */
int controller_makeInfo(LinkedList* pArrayListProductos)
{
   int retorno = 0;
   int ventasTotales, mayoresA10000, mayoresA20000, ventasTVsLCD;

   printf("\n*************************\n  Informe de ventas\n*************************\n");
   ventasTotales = ll_count(pArrayListProductos, ProductoVentasTotales);
   if(ventasTotales == -1){
       printf("No se ha podido hacer el conteo Total.");
       retorno = -1;
   }else{
       printf("-Cantidad de unidades vendidas totales: %d\n", ventasTotales);
   }

   mayoresA10000 = ll_count(pArrayListProductos, ProductoMayoresA10000);
   if(mayoresA10000 == -1){
       printf("No se ha podido hacer el conteo mayor a 10000.");
       retorno = -1;
   }else{
       printf("-Cantidad de unidades con precio mayor a 10000: %d\n", mayoresA10000);
   }

   mayoresA20000 = ll_count(pArrayListProductos, ProductoMayoresA20000);
   if(mayoresA20000 == -1){
       printf("No se ha podido hacer el conteo mayoor a 20000.");
       retorno = -1;
   }else{
       printf("-Cantidad de unidades con precio mayor a 20000: %d\n", mayoresA20000);
   }

   ventasTVsLCD = ll_count(pArrayListProductos, ProductoventasTVsLCD);
   if(ventasTVsLCD == -1){
       printf("No se ha podido hacer el conteo de venta de TVsLCD.");
       retorno = -1;
   }else{
       printf("-Cantidad de TVsLCD vendidos: %d\n", ventasTVsLCD);
   }
   printf("*************************\n");

   if(retorno != -1){
       FILE* lista = fopen("informes.txt", "w");

       if(lista==NULL){        //error del fopen
           printf("Error para guardar\n");
           return retorno;
       }

       fprintf(lista,"*************************\n  Informe de ventas\n*************************\n-Cantidad de unidades vendidas totales: %d\n-Cantidad de unidades con precio mayor a 100000: %d\n-Cantidad de unidades con precio mayor a 300000: %d\n-Cantidad de TVsLCD vendidos: %d\n*************************\n", ventasTotales, mayoresA10000, mayoresA20000, ventasTVsLCD);   //y lo guarda
       printf("Archivo guardado en 'informes.txt' con el informe de ventas.\n\n");

       fclose(lista);
   }else{
       printf("Debido a errores no se ha guardado el informe.\n");
   }
   return retorno;
}
