#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Prototipo.h"
#include "PrototipoTwo.h"
#include "parser.h"
#include "utn.h"
int controller_menu()
{
    int option = -1;
        printf("\n\t -Repaso Parcial N 2: LinkedList- \n\t\tGabriel Miranda \n\n");
        printf("1. Cargar archivo Prototipo 1 \n");
        printf("2. Imprimir contenido de prototipo 1. \n");
        printf("3. Cargar archivo prototipo 2:\n");
        printf("4. Imprimir contenido de prototipo 2 \n");
        printf("5. Salir. \n");
        utn_getNumero(&option,"\nIngrese una opcion:\n"
        	    			,"\nERROR ingrese una opcion valida\n",1,5,3);
        return option;
}

/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPrototipo LinkedList*
 * \return int
 *
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

/** \brief Lista los prototipos
 * \param pArrayListPrototipo LinkedList*
 * \return int
 */

int controller_ListPrototipo(LinkedList* pArrayListPrototipo)
{
	    int retorno = -1;
	    int i;
	    int auxPrimerParametro=0;
	    char auxSegundoParametro[SEGUNDO_LEN],auxTercerParametro[50], auxCuartoParametro[SEGUNDO_LEN];
	    Mensaje* auxP=NULL;
	    if((ll_len(pArrayListPrototipo))>0 &&pArrayListPrototipo!=NULL){
	    	printf("\n\t\t\t\tLISTADO DE MENSAJES\t\t\n\n\n");
	        for(i=0; i<ll_len(pArrayListPrototipo); i++){
	            auxP = (Mensaje*)ll_get(pArrayListPrototipo, i);

	            	prototipo_getPrimerParametro(auxP,&auxPrimerParametro);
			    	prototipo_getSegundoParametro(auxP,auxSegundoParametro);
			    	prototipo_getTercerParametro(auxP,auxTercerParametro);
			    	prototipo_getCuartoParametro(auxP,auxCuartoParametro);


	            if(auxP != NULL)
	            {	retorno=0;
	            	printf("\nID_MENSAJE[%d]\nID_USUARIO[%s]\nPOPULARIDAD [%s]\nMENSAJE [%s] \n\n",
	            			auxPrimerParametro,auxSegundoParametro,auxTercerParametro,auxCuartoParametro);	            }
	        }
	    }else{
	    	printf("\nNO HAY NADA PARA MOSTRAR\n");
	    }
	    return retorno;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPrototipo LinkedList*
 * \return int
 *
 */
int controller_loadFromTextTwo(char* path , LinkedList* pArrayListPrototipoTwo)
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
	    {   printf("Archivo encontrado y cargado. ");
	        parserTwo_PrototipoFromText(listaFT, pArrayListPrototipoTwo);
	        retorno=0;
	    }
	    return retorno;
}

/** \brief Lista los prototipos
 * \param pArrayListPrototipo LinkedList*
 * \return int
 */

int controller_ListPrototipoTwo(LinkedList* pArrayListPrototipoTwo)
{
	    int retorno = -1;
	    int i;
	    int auxPrimerParametro=0;
	    char auxSegundoParametro[50],auxTercerParametro[50];
	    PrototipoTwo* auxP=NULL;
	    if((ll_len(pArrayListPrototipoTwo))>0 &&pArrayListPrototipoTwo!=NULL){
	    	printf("\n\t\t\t\tLISTADO DE USUARIOS\t\t\n\n\n");
	    	printf("\nID_USUARIO\t\tNICK\t\tPOPULARIDAD\n");
	        for(i=0; i<ll_len(pArrayListPrototipoTwo); i++){
	            auxP = (PrototipoTwo*)ll_get(pArrayListPrototipoTwo, i);
	            	prototipoTwo_getPrimerParametro(auxP,&auxPrimerParametro);
			    	prototipoTwo_getSegundoParametro(auxP,auxSegundoParametro);
			    	prototipoTwo_getTercerParametro(auxP,auxTercerParametro);
	            if(auxP != NULL)
	            {	retorno=0;
	            	printf("%10d %19s %20s \n", auxPrimerParametro,auxSegundoParametro,auxTercerParametro);
	            }
	        }
	    }else{
	    	printf("\nNO HAY NADA PARA MOSTRAR\n");
	    }
	    return retorno;

}

int controller_saveAsTextModificacion(char* path , LinkedList* pArrayListPrototipo, LinkedList* pArrayListPrototipoTwo)
{
	 	int retorno = -1;
	    int auxPrimerParametro=0,auxPrimerParametroTwo=0;
	    char auxSegundoParametro[50],auxTercerParametro[50], auxCuartoParametro[CUARTO_LEN],
		auxSegundoParametroTwo[50],auxTercerParametroTwo[50];
	    Mensaje* this;
	    PrototipoTwo* this2;
	    FILE* lista = fopen("feed.csv", "w");
	    if(lista==NULL){
	        printf("Error para guardar\n");
	        retorno=-1;
	    }

	    fprintf(lista, "ID_MENSAJE,MENSAJE,POPULARIDAD,ID_USUARIO,NICK\n");
	        	if(pArrayListPrototipo!=NULL){
	        	        for(int i=0; i<ll_len(pArrayListPrototipo); i++){
	        	        for(int j=i+1;j<ll_len(pArrayListPrototipoTwo); j++){
	        	            this = (Mensaje*)ll_get(pArrayListPrototipo, i);
	        	        	this2=(PrototipoTwo*)ll_get(pArrayListPrototipoTwo, j);
	        	        	prototipo_getPrimerParametro(this,&auxPrimerParametro);
	        		    	prototipo_getSegundoParametro(this,auxSegundoParametro);
	        		    	prototipo_getTercerParametro(this,auxTercerParametro);
	       			    	prototipo_getCuartoParametro(this,auxCuartoParametro);
	       			    	prototipoTwo_getPrimerParametro(this2,&auxPrimerParametroTwo);
	       			    	prototipoTwo_getSegundoParametro(this2,auxSegundoParametroTwo);
	       			    	prototipoTwo_getTercerParametro(this2,auxTercerParametroTwo);


	        	        }	        	       fprintf(lista, "%d,%s,%s,%d,%s,%s\n",
	        	        		auxPrimerParametro,auxCuartoParametro,auxTercerParametro,auxPrimerParametroTwo,
	        	        		auxSegundoParametroTwo,auxTercerParametroTwo);

}

	        printf("Archivo Guardado.\n");
	        retorno = 1;

	        	}


        fclose(lista);
	    return retorno;
	    }



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Realiza un mapeo de los prototipos
 *
 * \param pArrayListPrototipo LinkedList*
 * \return int 0 = ok
 *
 */
/*
int controller_mapPrototipos(LinkedList* pArrayListPrototipo){
    int retorno = -1;

    if(ll_map(pArrayListPrototipo, prototipo_map) == 0){
      	retorno=0;
    }
    return retorno;
}
*/
/** \brief Realiza un mapeo de los prototiposTwo
 *
 * \param pArrayListPrototipo LinkedList*
 * \return int 0 = ok
 *
 */
/*
int controller_mapPrototiposTwo(LinkedList* pArrayListPrototipoTwo){
    int retorno = -1;

    if(ll_map(pArrayListPrototipoTwo, prototipoTwo_map) == 0){
      	retorno=0;
    }
    return retorno;
}
*/

/** \brief Guarda los datos de los prototipos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPrototipo LinkedList*
 * \return int
 *
 */
/*
int controller_saveAsTextModificacion(char* path , LinkedList* pArrayListPrototipo)
{
	 	int retorno = -1;
	    int auxPrimerParametro;
	    char auxSegundoParametro[50],auxTercerParametro[50], auxCuartoParametro[50];

	    Mensaje* this;

	    FILE* lista = fopen("data.csv", "w");


	    if(lista==NULL){
	        printf("Error para guardar\n");
	        retorno=-1;
	    }

	    fprintf(lista, "id,fecha,cantidad,monto\n");
	        	if(pArrayListPrototipo!=NULL){
	        	        for(int i=0; i<ll_len(pArrayListPrototipo); i++){
	        	            this = (Mensaje*)ll_get(pArrayListPrototipo, i);

	        	            prototipo_getPrimerParametro(this,&auxPrimerParametro);
	        		    	prototipo_getSegundoParametro(this,auxSegundoParametro);
	        		    	prototipo_getTercerParametro(this,auxTercerParametro);
	       			    	prototipo_getCuartoParametro(this,auxCuartoParametro);
	        	            fprintf(lista, "%d,%s,%s,%s\n",auxPrimerParametro,auxSegundoParametro,auxTercerParametro,auxCuartoParametro);

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
   int ventasTotales, mayoresA10000, mayoresA20000, ventasTVsLCD;

   printf("\n*************************\n  Informe de ventas\n*************************\n");
   ventasTotales = ll_count(pArrayListProductos, prototipoVentasTotales);
   if(ventasTotales == -1){
       printf("No se ha podido hacer el conteo Total.");
       retorno = -1;
   }else{
       printf("-Cantidad de unidades vendidas totales: %d\n", ventasTotales);
   }

   mayoresA10000 = ll_count(pArrayListProductos, prototipoMayoresAx);
   if(mayoresA10000 == -1){
       printf("No se ha podi do hacer el conteo mayor a 10000.");
       retorno = -1;
   }else{
       printf("-Cantidad de unidades con precio mayor a 10000: %d\n", mayoresA10000);
   }

   mayoresA20000 = ll_count(pArrayListProductos, prototipoMayoresAx);
   if(mayoresA20000 == -1){
       printf("No se ha podido hacer el conteo mayoor a 20000.");
       retorno = -1;
   }else{
       printf("-Cantidad de unidades con precio mayor a 20000: %d\n", mayoresA20000);
   }

   ventasTVsLCD = ll_count(pArrayListProductos, PrototipoMayorCantidadNombre);
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
*/
/*

int controller_filterPrototipo(LinkedList* pArrayListPrototipo)
{
    int retorno = -1;
    int option;
    int i;
    int acumuladorMonto=0;
    int acumuladorEntrada=0;
    int auxPrimerParametro;
    char auxSegundoParametro[50],auxTercerParametro[50], auxCuartoParametro[50], auxQuintoParametro[50];

    LinkedList* filterList;
    Prototipo* this;
    int auxCantidadThis,auxMontoFacturadoThis;
    utn_getNumero(&option,"\nIngrese la sala del 1 al 5\n","\nError\n",1,5,3);
    switch(option){
    case 1:
        filterList = ll_filter(pArrayListPrototipo, ProtipoFilterX);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Prototipo*)ll_get(filterList, i);

    	        	            prototipo_getPrimerParametro(this,&auxPrimerParametro);
    	        		    	prototipo_getSegundoParametro(this,auxSegundoParametro);
    	        		    	prototipo_getTercerParametro(this,auxTercerParametro);
    	       			    	prototipo_getCuartoParametro(this,auxCuartoParametro);
    	        		    	prototipo_getQuintoParametro(this,auxQuintoParametro);
       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxPrimerParametro);

        }
        printf("\nMonto total acumulado: [%d]\nCantidad total de entradas vendidas: [%d]\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 2:
        filterList = ll_filter(pArrayListPrototipo, movieFilterSala2);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Prototipo*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	prototipo_getSegundoParametro(this,auxPrimerParametro);

       	        		    		acumuladorEntrada+=auxCantidadThis;
       	        		        	acumuladorMonto+=auxMontoFacturadoThis;
           	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxPrimerParametro);

        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 3:
        filterList = ll_filter(pArrayListPrototipo, movieFilterSala3);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Prototipo*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	prototipo_getSegundoParametro(this,auxPrimerParametro);

       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxPrimerParametro);

        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 4:
        filterList = ll_filter(pArrayListPrototipo, movieFilterSala4);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Prototipo*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	prototipo_getSegundoParametro(this,auxPrimerParametro);

       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxPrimerParametro);


        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 5:
        filterList = ll_filter(pArrayListPrototipo, movieFilterSala5);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Prototipo*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	prototipo_getSegundoParametro(this,auxPrimerParametro);

       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxPrimerParametro);

        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    }

    return retorno;
}


*/
