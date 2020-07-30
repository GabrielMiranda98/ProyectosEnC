#include "utn.h"
#include "prestamo.h"
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

void hardcodePrestamo (ePrestamo* array,int estado, int size,int cantidadDeCuotasDelPrestamo, int idCliente, int idPrestamo,int importePrestamo)
{
    array[idPrestamo].cantidadDeCuotasDelPrestamo = cantidadDeCuotasDelPrestamo;
    array[idPrestamo].idCliente=idCliente;
    array[idPrestamo].estado=estado;
    array[idPrestamo].idPrestamo=idPrestamo;
    array[idPrestamo].importePrestamo=importePrestamo;
    array[idPrestamo].isEmptyPrestamo=0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int inicializarPrestamo(ePrestamo array[], int size)
{
	{
		int retorno=-1;
		    int i;
		    if(array!=NULL && size>=0)
		    {
		    	retorno=0;
		    	for(i=0;i<size;i++)
		    	{
		    		array[i].isEmptyPrestamo=1;
		    	}
			}
			    return retorno;


		}
}
int inicializarEstado(ePrestamo array[], int size)
{
	{
		int retorno=-1;
		    int i;
		    if(array!=NULL && size>=0)
		    {
		    	retorno=0;
		    	for(i=0;i<size;i++)
		    	{
		    		array[i].estado=1;
		    	}
			}
			    return retorno;


		}
}
int bajaCliente( eCliente array[], int size, int idCliente,ePrestamo array2[], int size2)
{
int retorno=-1;
int i ;
int opcion;
if(array!=NULL&&size>=0&&array2!=NULL&&size2>=0&&array[idCliente].isEmptyCliente==0)
{


			for(i=0;i<size2;i++)
			{

				if (array[idCliente].idCliente==array2[i].idCliente&&array2[i].isEmptyPrestamo==0)
				{printf("\nID PRESTAMO\t\tIMPORTE\t\tCANTIDAD DE CUOTAS\t\tESTADO(1-SALDADO / 0-A PAGAR)\n");
				printf("\n%10d %20d %20d %20d \n",array2[i].idPrestamo,array2[i].importePrestamo,array2[i].cantidadDeCuotasDelPrestamo,array2[i].estado);}

				}
			   printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\n");
				printf("[%10d] %17s %15s %25s %15d %20d\n"
						,array[idCliente].idCliente,array[idCliente].nombreCliente,array[idCliente].apellidoCliente,array[idCliente].cuilCliente,array[idCliente].cPrestamoActivo,array[idCliente].cPrestamoSaldado);


			utn_getUnsignedInt("\n1-DAR DE BAJA AL CLIENTE.\n2-CANCELAR\n","\nError\n",1,sizeof(int),1,2,3,&opcion);

			if(opcion==1)
		{
			array[idCliente].isEmptyCliente=1;
			retorno=0;
		}
		else
		{
			printf("\nCANCELADO\n");
		}



			}
else
{
	printf("\n[ID NO ENCONTRADO]\n");
}






return retorno;}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscarEmptyPrestamo(ePrestamo array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyPrestamo==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int buscarPrestamo(ePrestamo* array, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyPrestamo==1)
                continue;
            else if(array[i].idPrestamo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int altaPrestamo(ePrestamo array[], int size, int* contadorID,int indice,eCliente array2[], int size2, int idCliente)
	{
    int retorno=-1;
    int auxiliarIdCliente;
    int acumuladorDePrestamos;
    int cPrestamoActivo;
    ePrestamo auxPrestamo;
    if(array!=NULL&&size>0&&contadorID!=NULL&&array2!=NULL&&size2>0)
    {
    	if(buscarCliente(array2,size2,idCliente,&auxiliarIdCliente)==0)
    	{
    	if(	utn_getUnsignedInt("\nIngrese el importe del Prestamo:","\nError\n",1,30,100,100000,3,&auxPrestamo.importePrestamo)==0&&
    			utn_getUnsignedInt("\nIngrese la cantidad de cuotas del Prestamo:","\nError\n",0,3,1,12,3,&auxPrestamo.cantidadDeCuotasDelPrestamo)==0
    	)
 	   {

    		retorno=0;
    		auxPrestamo.idPrestamo=*contadorID;
    		auxPrestamo.isEmptyPrestamo=0;

    		auxPrestamo.importePrestamo+=array2[idCliente].acumuladorDeMonto;
    		array2[idCliente].acumuladorDeMonto=	auxPrestamo.importePrestamo;

    		auxPrestamo.cantidadDeCuotasDelPrestamo+=array2[idCliente].cuotasAcumuladas;
    		array2[idCliente].cuotasAcumuladas=	auxPrestamo.cantidadDeCuotasDelPrestamo;

    		auxPrestamo.estado=0;
    		auxPrestamo.idCliente=idCliente;

    		acumuladorDePrestamos=array2[idCliente].cantidadDePrestamos+1;
    		array2[idCliente].cantidadDePrestamos=acumuladorDePrestamos;

    		cPrestamoActivo=array2[idCliente].cPrestamoActivo+1;
    		array2[idCliente].cPrestamoActivo=cPrestamoActivo;


    		array2[idCliente].estadoPrestamos=0;
   		 printf("\nID PRESTAMO\t\tIMPORTE\t\tCANTIDAD DE CUOTAS\t\tESTADO(1-SALDADO / 0-A PAGAR)\n");
   			printf("\n[%10d] %20d %20d %20d  \n"
   			    							,auxPrestamo.idPrestamo,auxPrestamo.importePrestamo,auxPrestamo.cantidadDeCuotasDelPrestamo,auxPrestamo.estado);



		   printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\tMonto total a pagar:\tTotal de cuotas:\n");
			printf("[%10d] %17s %15s %25s %15d %20d %20d %20d\n"
					,array2[idCliente].idCliente,array2[idCliente].nombreCliente,array2[idCliente].apellidoCliente,array2[idCliente].cuilCliente,array2[idCliente].cPrestamoActivo,array2[idCliente].cPrestamoSaldado,array2[idCliente].acumuladorDeMonto,array2[idCliente].cantidadDePrestamos);


    		array[*contadorID]=auxPrestamo;

    		(*contadorID)++;

    	}
    	else
    	{
    		{ printf("\t[NO EXISTE EL ID DEL CLIENTE]\t");
    		retorno=0;}

    	}

    }
    }

    return retorno;
}
int bajaPrestamo(ePrestamo array[], int size, int idPrestamo,eCliente array2[], int size2)
{
int retorno=-1;
int i ;
int opcion;
int cPrestamoSaldado;
int	cPrestamoActivo;
if(array!=NULL&&size>=0&&array2!=NULL&&size2>=0&&array[idPrestamo].isEmptyPrestamo==0)
{
			for(i=0;i<size2;i++)
			{
			if
		(array[idPrestamo].idCliente==array2[i].idCliente&&array2[i].isEmptyCliente==0 && array2[i].cPrestamoActivo>0)
				{
		 		   printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\n");
		 			printf("[%10d] %17s %15s %25s %15d %20d\n"
		 					,array2[i].idCliente,array2[i].nombreCliente,array2[i].apellidoCliente,array2[i].cuilCliente,array2[i].cPrestamoActivo,array2[i].cPrestamoSaldado);

		   	   utn_getUnsignedInt("\n1-TRANSFORMAR EL PRESTAMO DE 'ACTIVO' A 'SALDADO' . \n2-CANCELAR\n","\nERROR\n",0,3,1,2,3,&opcion);
		if(opcion==1 )  {
			retorno=0;
			array[idPrestamo].isEmptyPrestamo=0;
			array[idPrestamo].estado=1;
			cPrestamoSaldado=array2[i].cPrestamoSaldado+1;
    		array2[i].cPrestamoSaldado=cPrestamoSaldado;
    		cPrestamoActivo=array2[i].cPrestamoActivo-1;
    		array2[i].cPrestamoActivo=cPrestamoActivo;

    		array2[i].acumuladorDeMonto-=array[idPrestamo].importePrestamo;

    		array2[i].cuotasAcumuladas-=	array[idPrestamo].cantidadDeCuotasDelPrestamo;


    		  printf("\nTransformacion Exitosa\n");
		}
		else
		{printf("\nCANCELADO\n");}

				}

			}


}
else
{
	printf("\n[ID NO ENCONTRADO]\n");
}

return retorno;}
int modificarPrestamo(ePrestamo array[], int size, int idPrestamo,eCliente array2[], int size2)
{
int retorno=-1;
int i ;
int opcion;
int cPrestamoSaldado;
int cPrestamoActivo;
if(array!=NULL&&size>=0&&array2!=NULL&&size2>=0&&array[idPrestamo].estado==1&&array[idPrestamo].isEmptyPrestamo==0)
{
			for(i=0;i<size2;i++)
			{
			if
		(array[idPrestamo].idCliente==array2[i].idCliente&&array2[i].isEmptyCliente==0 && array2[i].cPrestamoSaldado>0)
				{
		 		   printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\n");
		 			printf("[%10d] %17s %15s %25s %15d %20d\n"
		 					,array2[i].idCliente,array2[i].nombreCliente,array2[i].apellidoCliente,array2[i].cuilCliente,array2[i].cPrestamoActivo,array2[i].cPrestamoSaldado);


		   	   utn_getUnsignedInt("\n1-TRANSFORMAR EL PRESTAMO DE 'SALDADO' A 'ACTIVO' . \n2-CANCELAR\n","\nERROR\n",0,3,1,2,3,&opcion);
		if(opcion==1)  {
			retorno=0;
			array[idPrestamo].isEmptyPrestamo=0;
			array[idPrestamo].estado=0;
			cPrestamoSaldado=array2[i].cPrestamoSaldado-1;
		    array2[i].cPrestamoSaldado=cPrestamoSaldado;
		    cPrestamoActivo=array2[i].cPrestamoActivo+1;
		    array2[i].cPrestamoActivo=cPrestamoActivo;

    		array[idPrestamo].importePrestamo+=array2[i].acumuladorDeMonto;
    		array2[i].acumuladorDeMonto=array[idPrestamo].importePrestamo;

    		array[idPrestamo].cantidadDeCuotasDelPrestamo-=array2[i].cuotasAcumuladas;
    		array2[i].cuotasAcumuladas=	array[idPrestamo].cantidadDeCuotasDelPrestamo;

		    printf("\nTransformacion Exitosa\n");
		}
		else
		{
			printf("\nCANCELADO\n");
		}

				}

			}


}
else
{
	printf("\n[ID NO ENCONTRADO]\n");
}



return retorno;}
