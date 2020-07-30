#include "cliente.h"
#include "prestamo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
int cli_imprimir(eCliente* array)
{
	int retorno=-1;
	if(array!=NULL&&array->isEmptyCliente==0)
	{
		retorno=0;

		printf("[%10d] %17s %15s %25s %15d \n"
				,array->idCliente,array->nombreCliente,array->apellidoCliente,array->cuilCliente,array->cPrestamoActivo);
	}
return retorno;}
int imprimirCliente(eCliente array[],int size)
{
	int retorno=-1;
	    int i;
	    if(array!=NULL && size>=0)
	    { 	printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\tMonto acumulado\tCuotas totales\n");
	    		    							    	retorno=0;
	    	for(i=0;i<size;i++)
	    	{
	    		if(array[i].isEmptyCliente==0)
	    		{

	    			printf("[%10d] %17s %15s %25s %15d %20d %20d %20d\n"
	    											,array[i].idCliente,array[i].nombreCliente,array[i].apellidoCliente,array[i].cuilCliente,array[i].cPrestamoActivo,array[i].cPrestamoSaldado,array[i].acumuladorDeMonto,array[i].cuotasAcumuladas);


	    		}
	    		}
		}
		    return retorno;


	}
int informarClientesPrestamos(eCliente array[],int size)
{
	int retorno = -1;
		int opcion = 0;
		int i;
		int mayorCliente = 0;
		char auxN[51];
		char auxApe[51];
		int idCliente=0;
		int flag=-1;
		char auxCuil[51];
		int cPrestamoActivo;
			int cPrestamoSaldado;
			int acumuladorDeMonto;
			int cuotasAcumuladas;
		if(array != NULL && size>0)
		{
			utn_getUnsignedInt("\nn1-Cliente con más préstamos activos.\n2-Cliente con más préstamos saldados.\n3-Cliente con más préstamos.\n4-Salir\nIngrese opcion: ","\nError.",1,sizeof(int),1,size,3,&opcion);

			switch(opcion)
			{
			case 1:
				for(i=0;i<size;i++)
				{
					if( array[i].isEmptyCliente == 0 &&
							array[i].cPrestamoActivo>0 &&
							array[i].cantidadDePrestamos>0)

					{
					if(array[i].cPrestamoActivo > mayorCliente)
					{
						mayorCliente = array[i].cPrestamoActivo;
						idCliente = array[i].idCliente;
						strcpy(auxN,array[i].nombreCliente);
						strcpy(auxApe,array[i].apellidoCliente);
						strcpy(auxCuil,array[i].cuilCliente);
				 cPrestamoActivo= array[i].cPrestamoActivo;
				 cPrestamoSaldado= array[i].cPrestamoSaldado;
				 acumuladorDeMonto= array[i].acumuladorDeMonto;
				 cuotasAcumuladas=array[i].cuotasAcumuladas;
						flag=0;
					}

					}

				}
				if(flag==0)
				{
					printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\tMonto acumulado\tCuotas totales\n");
					printf("[%10d] %17s %15s %25s %15d %20d %20d %20d\n"
				    											,idCliente,auxN,auxApe,auxCuil,cPrestamoActivo,cPrestamoSaldado,acumuladorDeMonto,cuotasAcumuladas);




				}
				else
				{
					printf("\nError\n");
				}
				retorno = 0;
				break;

			case 2:
				for(i=0;i<size;i++)
				{
					if( array[i].isEmptyCliente == 0 &&
							array[i].cPrestamoSaldado>0 &&
							array[i].cantidadDePrestamos>0)

					{
					if(array[i].cPrestamoSaldado > mayorCliente)
					{
						mayorCliente = array[i].cPrestamoActivo;
						idCliente = array[i].idCliente;
						strcpy(auxN,array[i].nombreCliente);
						strcpy(auxApe,array[i].apellidoCliente);
						strcpy(auxCuil,array[i].cuilCliente);
						cPrestamoActivo= array[i].cPrestamoActivo;
						cPrestamoSaldado= array[i].cPrestamoSaldado;
						acumuladorDeMonto= array[i].acumuladorDeMonto;
						cuotasAcumuladas=array[i].cuotasAcumuladas;
						flag=0;
					}

					}

				}
				if(flag==0)
				{
					printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\tMonto acumulado\tCuotas totales\n");
					printf("[%10d] %17s %15s %25s %15d %20d %20d %20d\n"
				    											,idCliente,auxN,auxApe,auxCuil,cPrestamoActivo,cPrestamoSaldado,acumuladorDeMonto,cuotasAcumuladas);




				}
				else
				{
					printf("\nError\n");
				}
				retorno = 0;
				break;
			case 3:
				for(i=0;i<size;i++)
				{
					if( array[i].isEmptyCliente == 0 &&
							array[i].cantidadDePrestamos>0)

					{
					if(array[i].cantidadDePrestamos > mayorCliente)
					{
						mayorCliente = array[i].cPrestamoActivo;
						idCliente = array[i].idCliente;
						strcpy(auxN,array[i].nombreCliente);
						strcpy(auxApe,array[i].apellidoCliente);
						strcpy(auxCuil,array[i].cuilCliente);
				 cPrestamoActivo= array[i].cPrestamoActivo;
				 cPrestamoSaldado= array[i].cPrestamoSaldado;
				 acumuladorDeMonto= array[i].acumuladorDeMonto;
				 cuotasAcumuladas=array[i].cuotasAcumuladas;
						flag=0;
					}

					}

				}
				if(flag==0)
				{
					printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\tMonto acumulado\tCuotas totales\n");
					printf("[%10d] %17s %15s %25s %15d %20d %20d %20d\n"
				    											,idCliente,auxN,auxApe,auxCuil,cPrestamoActivo,cPrestamoSaldado,acumuladorDeMonto,cuotasAcumuladas);




				}
				else
				{
					printf("\nError\n");
				}
				retorno = 0;
break;
		}
		}
return retorno;}


	/*
int retorno=-1;
int i;
int maxA=0;
int maxS=0;
int maxC=0;
int opcion;
eCliente eAuxA;
eCliente eAuxS;
eCliente eAuxC;

eAuxA.isEmptyCliente=1;
eAuxA.cantidadDePrestamos=0;
eAuxA.cPrestamoActivo=0;
eAuxA.cPrestamoSaldado=0;
eAuxA.estadoPrestamos=0;
eAuxA.acumuladorDeMonto=0;
eAuxA.cuotasAcumuladas=0;

eAuxS.isEmptyCliente=1;
eAuxS.cantidadDePrestamos=0;
eAuxS.cPrestamoActivo=0;
eAuxS.cPrestamoSaldado=0;
eAuxS.estadoPrestamos=0;
eAuxS.acumuladorDeMonto=0;
eAuxS.cuotasAcumuladas=0;

eAuxC.isEmptyCliente=1;
eAuxC.cantidadDePrestamos=0;
eAuxC.cPrestamoActivo=0;
eAuxC.cPrestamoSaldado=0;
eAuxC.estadoPrestamos=0;
eAuxC.acumuladorDeMonto=0;
eAuxC.cuotasAcumuladas=0;


if(array!=NULL&&size>0)
		{

			utn_getNumero(&opcion,"\n1-Cliente con más préstamos activos.\n2-Cliente con más préstamos saldados\n3-Cliente con  más prestamos\n","\nError\n",1,3,3);

			switch(opcion)
			{
			case 1:
								for(i=0;i<size;i++)
								{
									if(array[i].isEmptyCliente==0 )
									{

										if(array[i].cPrestamoActivo>maxA &&array[i].cPrestamoActivo>0)
										{
											maxA=eAuxA.cPrestamoActivo;
											eAuxA=array[i];

										}
									}
								}

									printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\n");
									printf("[%10d] %17s %15s %25s %15d %20d\n"
														,eAuxA.idCliente,eAuxA.nombreCliente,eAuxA.apellidoCliente,eAuxA.cuilCliente,eAuxA.cPrestamoActivo,eAuxA.cPrestamoSaldado);

								   retorno=0;
								break;


			case 2:
				for(i=0;i<size;i++)
				{
					if(array[i].isEmptyCliente==0)
					{

						if(array[i].cPrestamoSaldado>maxS &&array[i].cPrestamoSaldado>0)
						{
							maxS=eAuxS.cPrestamoSaldado;
							eAuxS=array[i];

						}
					}
				}

					printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\n");
					printf("[%10d] %17s %15s %25s %15d %20d\n"
										,eAuxS.idCliente,eAuxS.nombreCliente,eAuxS.apellidoCliente,eAuxS.cuilCliente,eAuxS.cPrestamoActivo,eAuxS.cPrestamoSaldado);

				   retorno=0;
				break;
			case 3:
				for(i=0;i<size;i++)
				{
					if(array[i].isEmptyCliente==0)
					{

						if(array[i].cantidadDePrestamos>maxC &&array[i].cantidadDePrestamos>0)
						{
							maxC=eAuxC.cantidadDePrestamos;
							eAuxC=array[i];

						}
					}
				}

					printf("\nID CLIENTE\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPrestamos Activos\tPrestamos Saldados\n");
					printf("[%10d] %17s %15s %25s %15d %20d\n"
										,eAuxC.idCliente,eAuxC.nombreCliente,eAuxC.apellidoCliente,eAuxC.cuilCliente,eAuxC.cPrestamoActivo,eAuxC.cPrestamoSaldado);

				   retorno=0;
				break;

		}
*/
int pre_imprimir(ePrestamo* array)
{
	int retorno=-1;
	if(array!=NULL&&array->isEmptyPrestamo==0&&array->estado==0)
	{
		retorno=0;
		printf("\n[%10d] %20d %20d %20d \n"
	    							,array->idPrestamo,array->importePrestamo,array->cantidadDeCuotasDelPrestamo,array->estado);

	}
return retorno;}
int imprimirPrestamo(ePrestamo array[],int size,eCliente array2[], int size2)
{
	int retorno=-1;
	    int i;
	    int j;
	 if(array!=NULL && size>0&&array2!=NULL && size2>0)
	 {
		 printf("\nID PRESTAMO\t\tIMPORTE\t\tCANTIDAD DE CUOTAS\t\tCUIL CLIENTE\t\tESTADO(1-SALDADO / 0-A PAGAR)\tIMPORTE: \n");

		 for(i=0;i<size;i++)
	    	{
	    		if(array[i].isEmptyPrestamo==0)
	    {
	    			for(j=0;j<size2;j++)
	    		{
	    			if(array2[j].isEmptyCliente==0&&array2[j].cantidadDePrestamos>0)
	    			{

	    				if(array[i].idCliente==array2[j].idCliente && array[i].estado==0)
	    				{
	    					printf("\n%10d %20d %20d %25s %20d %25d \n"
	    							,array[i].idPrestamo,array[i].importePrestamo,array[i].cantidadDeCuotasDelPrestamo,array2[j].cuilCliente,array[i].estado,array[i].importePrestamo);
	    					retorno=0;
	    				}


	    				}
	    			}


	    		}

	    }

	    	}
return retorno;
}
int informarPrestamos(ePrestamo array[],int size)
{ int retorno=-1;
	int importe;
	int cuotas;
	int i;
	int contador=0;
	int opcion;
	if(array!=NULL&&size>0)
	{		utn_getNumero(&opcion,"\n1-Cantidad de préstamos de importe mayor a 1000.\n2-Préstamos de 12 cuotas saldados.\n3Préstamos por cuotas\n","\nError\n",1,3,3);

	switch(opcion)
	{
	case 1:
		utn_getNumero(&importe,"\nIngrese un importe mayor a 1000\n","\nerror\n",1000,10000,3);
		if(importe>=1000)
		{
			for(i=0;i<size;i++)
			{
				if
				(array[i].importePrestamo>=importe&&
				array[i].isEmptyPrestamo==0 &&
				array[i].estado==0
						)
				{
					pre_imprimir(array);
					contador++;
				}

			}
				printf("\n LA CANTIDAD DE PRESTAMOS ACTIVOS SON : [%d] \n",contador);


		}
		retorno=0;
		break;

	case 2:
					for(i=0;i<size;i++)
					{
						if
						(
						array[i].isEmptyPrestamo==0 &&
						array[i].estado==1 &&
						array[i].cantidadDeCuotasDelPrestamo==12
								)
						{
							printf("\nID PRESTAMO\t\tIMPORTE\t\tCANTIDAD DE CUOTAS\t\tESTADO(1-SALDADO / 0-A PAGAR)\n");
											printf("\n%10d %20d %20d %20d \n",array[i].idPrestamo,array[i].importePrestamo,array[i].cantidadDeCuotasDelPrestamo,array[i].estado);
						}

					}

				retorno=0;
				break;
		break;

	case 3:
		utn_getNumero(&cuotas,"\nIngrese la cantidad de cuotas\n","\nerror\n",1,24,3);
		if(cuotas>=1)
		{
			for(i=0;i<size;i++)
			{
				if
				(
				array[i].cantidadDeCuotasDelPrestamo>=cuotas&&
				array[i].isEmptyPrestamo==0 &&
				array[i].estado==0
						)
				{
					printf("\nID PRESTAMO\t\tIMPORTE\t\tCANTIDAD DE CUOTAS\t\tESTADO(1-SALDADO / 0-A PAGAR)\n");
									printf("\n%10d %20d %20d %20d \n",array[i].idPrestamo,array[i].importePrestamo,array[i].cantidadDeCuotasDelPrestamo,array[i].estado);
				}

			}

		}
		retorno=0;
		break;

		break;

	}


	}

return retorno;}

