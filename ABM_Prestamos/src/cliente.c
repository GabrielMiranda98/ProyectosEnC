#include "cliente.h"
#include "informes.h"
#include "prestamo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


void hardcodeCliente (eCliente array[], int size, int id, char nombre[], char apellido[], char cuil[], int cantidadDeprestamos, int cuotas, int activo,int saldado)
{
    array[id].idCliente = id;
    strcpy(array[id].nombreCliente, nombre);
    strcpy(array[id].apellidoCliente, apellido);
    strcpy(array[id].cuilCliente, cuil);
    array[id].cPrestamoActivo=activo;
    array[id].cPrestamoSaldado=saldado;
    array[id].cuotasAcumuladas=cuotas;
    array[id].isEmptyCliente = 0;
    array[id].cantidadDePrestamos=0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int inicializarCliente(eCliente array[], int size)
{
	{
		int retorno=-1;
		    int i;
		    if(array!=NULL && size>=0)
		    {
		    	retorno=0;
		    	for(i=0;i<size;i++)
		    	{
		    		array[i].isEmptyCliente=1;
		    	}
			}
			    return retorno;


		}
}
int inicializarMonto(eCliente array[], int size)
{
	{
		int retorno=-1;
		    int i;
		    if(array!=NULL && size>=0)
		    {
		    	retorno=0;
		    	for(i=0;i<size;i++)
		    	{
		    		array[i].acumuladorDeMonto=0;
		    	}
			}
			    return retorno;


		}
}
int inicializarCuotas(eCliente array[], int size)
{
	{
		int retorno=-1;
		    int i;
		    if(array!=NULL && size>=0)
		    {
		    	retorno=0;
		    	for(i=0;i<size;i++)
		    	{
		    		array[i].cuotasAcumuladas=0;
		    	}
			}
			    return retorno;


		}
}
int inicializarcPrestamoActivo(eCliente array[], int size)
{
				int retorno=-1;
			    int i;
			    if(array!=NULL && size>=0)
			    {
			    	retorno=0;
			    	for(i=0;i<size;i++)
			    	{
			    		array[i].cPrestamoActivo=0;
			    	}
				}
				    return retorno;

    }
int inicializarcPrestamoSaldado(eCliente array[], int size)
{
	int retorno=-1;
				    int i;
				    if(array!=NULL && size>=0)
				    {
				    	retorno=0;
				    	for(i=0;i<size;i++)
				    	{
				    		array[i].cPrestamoSaldado=0;
				    	}
					}
    return retorno;
}
int inicializarCantidadDePrestamos(eCliente array[], int size)
{
	int retorno=-1;
				    int i;
				    if(array!=NULL && size>=0)
				    {
				    	retorno=0;
				    	for(i=0;i<size;i++)
				    	{
				    		array[i].cantidadDePrestamos=0;
				    	}
					}
    return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscarCliente(eCliente array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyCliente==1)
                continue;
            else if(array[i].idCliente==valorBuscado)
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
int altaCliente(eCliente array[], int size, int* contadorID)
{
    int retorno=-1;
    eCliente auxCliente;

    if(array!=NULL && size>0 && contadorID!=NULL)
    {
    	if
		(
    		utn_getName("\nIngrese el nombre del Cliente : ","\nError",1,51,3,auxCliente.nombreCliente)==0&&
		    utn_getName("\nIngrese el apellido del Cliente : ","\nError",1,51,3,auxCliente.apellidoCliente)==0&&
			utn_getCuil(auxCliente.cuilCliente,14,"\nIngrese el CUIL del Cliente :\n","\nError\n",3)==0
		)
    	{
    		retorno=0;
    		auxCliente.idCliente=*contadorID;
    		auxCliente.isEmptyCliente=0;
    		auxCliente.cantidadDePrestamos=0;
    		auxCliente.cPrestamoActivo=0;
    		auxCliente.cPrestamoSaldado=0;
    		auxCliente.estadoPrestamos=0;
    		auxCliente.acumuladorDeMonto=0;
    		auxCliente.cuotasAcumuladas=0;

    		array[*contadorID]=auxCliente;
    		  printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\n");
	 			printf("[%10d] %17s %15s %25s %15d %20d\n"
	 					,auxCliente.idCliente,auxCliente.nombreCliente,auxCliente.apellidoCliente,auxCliente.cuilCliente,auxCliente.cPrestamoActivo,auxCliente.cPrestamoSaldado);

	 			printf("\nAlta de cliente exitosa\n");
    		(*contadorID)++;}
    	}
    else
    {
		printf("\nALTA DENEGADA\n");

    }

    return retorno;
}
int modificarCliente(eCliente array[],int limite, int indice)
{
	int retorno=-1;
	int opcion;
	if(array!=NULL&&limite>0&&indice<limite&&indice>=0&&array[indice].isEmptyCliente==0)
	{
		utn_getUnsignedInt("\n¿Que desea modificar?\n1-NOMBRE\n2-APELLIDO\n3-CUIL\n4-TODOS LOS CAMPOS\n","\nError\n",1,sizeof(int),0,4,3,&opcion);

		switch(opcion)
		{
		case 1:
			utn_getName("\nIngrese el nombre del Cliente : ","\nError",1,51,3,array[indice].nombreCliente);
		break;
		case 2:
			  utn_getName("\nIngrese el apellido del Cliente : ","\nError",1,51,3,array[indice].apellidoCliente);
			  break;
		case 3:
			   utn_getDNI("\nIngrese el cuil del Cliente :\n","\nError\n",10,15,3,array[indice].cuilCliente);
				break;
		case 4:
			utn_getName("\nIngrese el nombre del Cliente : ","\nError",1,51,3,array[indice].nombreCliente);
			  utn_getName("\nIngrese el apellido del Cliente : ","\nError",1,51,3,array[indice].apellidoCliente);
			   utn_getDNI("\nIngrese el cuil del Cliente :\n","\nError\n",10,15,3,array[indice].cuilCliente);

			  break;

			retorno=0;
		}
	}
	else
	{
		printf("\n[ID NO ENCONTRADO]\n");
	}
return retorno;}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
