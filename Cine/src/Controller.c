#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "parser.h"
#include "utn.h"
int controller_menu()
{
    int option = -1;
        printf("\n\t -Repaso Parcial N 2: LinkedList- \n\t\tGabriel Miranda \n\n");
        printf("1. Cargar archivo data.csv (modo texto). \n");
        printf("2. Imprimir Ventas. \n");
        printf("3. Generar archivo de montos:\n");
        printf("4. Informes \n");
        printf("5. Salir. \n");
        utn_getNumero(&option,"\nIngrese una opcion:\n"
        	    			,"\nERROR ingrese una opcion valida\n",1,5,3);
        return option;
}

/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListMovies LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListMovies)
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
	        parser_MoviesFromText(listaFT, pArrayListMovies);
	        retorno=0;
	    }
	    return retorno;
}

/** \brief Lista las ventas
 * \param pArrayListMovies LinkedList*
 * \return int
 */

int controller_ListMovies(LinkedList* pArrayListMovies)
{
	    int retorno = -1;
	    int i;
	    int auxIdThis=0,auxSalaThis=0,auxCantidadThis=0;
	    char auxNomThis[50],auxHorasThis[50], auxDiaThis[50];
	    Movies* auxP=NULL;
	    if((ll_len(pArrayListMovies))>0 &&pArrayListMovies!=NULL){
	    	printf("\n\t\t\t\tTABLA CON DATOS DE VENTAS\t\t\n\n\n");
	    	printf("\tID\t\tNOMBRE PELICULA\t\tDIA\t\tHORARIO\t\tSALA\t\tCANTIDAD ENTRADAS\n");
	        for(i=0; i<ll_len(pArrayListMovies); i++){
	            auxP = (Movies*)ll_get(pArrayListMovies, i);


	            	movies_getId(auxP,&auxIdThis);
			    	movies_getNombre(auxP,auxNomThis);
			    	movies_getDiaChar(auxP,auxDiaThis);
			    	movies_getHorario(auxP,auxHorasThis);
			    	movies_getsala(auxP,&auxSalaThis);
			    	movies_getcantidadEntradas(auxP,&auxCantidadThis);

	            if(auxP != NULL)
	            {	retorno=0;
	            	printf("%10d %19s %20s %20s %10d %20d \n", auxIdThis,auxNomThis,auxDiaThis,auxHorasThis,auxSalaThis,auxCantidadThis);
	            }
	        }
	    }else{
	    	printf("\nNO HAY VENTAS PARA MOSTRAR\n");
	    }
	    return retorno;

}

/** \brief Realiza un mapeo de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 = ok
 *
 */

int controller_mapMovie(LinkedList* pArrayListMovies){
    int retorno = -1;

    if(ll_map(pArrayListMovies, movieMapMontofacturado) == 0){
      	retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsTextMontoFacturado(char* path , LinkedList* pArrayListMovies)
{
	 	int retorno = -1;
	    int auxIdThis,auxSalaThis,auxCantidadThis,auxMontoFacturadoThis,auxDiaThis;
	    char auxNomThis[50],auxHorasThis[50];

	    Movies* this;

	    FILE* lista = fopen("data_MontoFacturado.csv", "w");


	    if(lista==NULL){
	        printf("Error para guardar\n");
	        retorno=-1;
	    }

	    fprintf(lista, "id_venta, nombre_pelicula, dia, horario, sala, cantidad_entradas,monto_facturado\n");
	        	if(pArrayListMovies!=NULL){
	        	        for(int i=0; i<ll_len(pArrayListMovies); i++){
	        	            this = (Movies*)ll_get(pArrayListMovies, i);

	                    	movies_getId(this,&auxIdThis);
	        		    	movies_getNombre(this,auxNomThis);
	        		    	movies_getDiaInt(this,&auxDiaThis);
	        		    	movies_getHorario(this,auxHorasThis);
	        		    	movies_getsala(this,&auxSalaThis);
	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
	        	            fprintf(lista, "%d,%s,%d,%s,%d,%d,%d\n",auxIdThis,auxNomThis,auxDiaThis,auxHorasThis,auxSalaThis,auxCantidadThis,auxMontoFacturadoThis);

	        	        }
	        printf("Archivo Guardado.\n");
	        retorno = 1;
	    }


        fclose(lista);
	    return retorno;
	    }

int controller_filterMovies(LinkedList* pArrayListMovies)
{
    int retorno = -1;
    int option;
    int i;
    int acumuladorMonto=0;
    int acumuladorEntrada=0;
    char auxNombre[50];
    LinkedList* filterList;
    Movies* this;
    int auxCantidadThis,auxMontoFacturadoThis;
    utn_getNumero(&option,"\nIngrese la sala del 1 al 5\n","\nError\n",1,5,3);
    switch(option){
    case 1:
        filterList = ll_filter(pArrayListMovies, movieFilterSala1);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Movies*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	movies_getNombre(this,auxNombre);
       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxNombre);

        }
        printf("\nMonto total acumulado: [%d]\nCantidad total de entradas vendidas: [%d]\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 2:
        filterList = ll_filter(pArrayListMovies, movieFilterSala2);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Movies*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	movies_getNombre(this,auxNombre);

       	        		    		acumuladorEntrada+=auxCantidadThis;
       	        		        	acumuladorMonto+=auxMontoFacturadoThis;
           	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxNombre);

        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 3:
        filterList = ll_filter(pArrayListMovies, movieFilterSala3);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Movies*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	movies_getNombre(this,auxNombre);

       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxNombre);

        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 4:
        filterList = ll_filter(pArrayListMovies, movieFilterSala4);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Movies*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	movies_getNombre(this,auxNombre);

       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxNombre);


        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    case 5:
        filterList = ll_filter(pArrayListMovies, movieFilterSala5);

        for(i=0; i<ll_len(filterList); i++){
       	        	            this = (Movies*)ll_get(filterList, i);

       	        		    	movies_getcantidadEntradas(this,&auxCantidadThis);
       	        		    	movies_getmontoFacturado(this,&auxMontoFacturadoThis);
       	        		    	movies_getNombre(this,auxNombre);

       	        		    	acumuladorEntrada+=auxCantidadThis;
       	        		    	acumuladorMonto+=auxMontoFacturadoThis;
       	        		    	printf("\nNombres de las peliculas proyectadas en la sala : [%s]\n",auxNombre);

        }
        printf("\nMonto: %d\nCantidad: %d\n",acumuladorMonto,acumuladorEntrada);

        retorno=0;
        break;
    }

    return retorno;
}


