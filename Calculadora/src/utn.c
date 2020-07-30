#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Verifica	si esta dentro de 0 y 9 (Que no sea letra)
static int esNumerica(char*cadena)
{
	int retorno=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9'){break;}
			i++;
		}
	}
	if(cadena[i]=='\0'){retorno=1;}
return retorno;
}


//Verifica uno por uno
static int getInt(int*pResultado)
{	int retorno=-1;
	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	fflush(stdin);
	buffer[strlen(buffer)-1]='\0';
	if(esNumerica(buffer))
	{
	*pResultado=atoi(buffer);
	retorno=1;}
	return retorno;}

//Pide un resultado, mensaje, mensaje error, minimo, maximo, reintento
int utn_getNumero(int* pResultado,char * mensaje, char * mensajeError , int minimo , int maximo , int reintentos)
{
	int retorno;
	int numero;

	while(reintentos>0)
	{
		printf(mensaje);
		fflush(stdin);
		if(getInt(&numero)==1)
		if(numero<=maximo&&numero>=minimo){break;}
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos==0)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
		*pResultado=numero;
	}
	return retorno;

}

//Calcula area de un circulo
int calculoCirculo(int n)
{
	float area;
	area=(n*n)*3.14;
return area;
}

/*int calculoDife(int x, int y)
{

}/*/

//calcula una multiplicacion
int calculoMultiplicar (int x, int y)
{
	int tot;
	tot=x*y;
	return tot;
}

//calcula una suma
int calculoSuma (int x, int y)
{
	int tot;
	tot=x+y;
	return tot;
}

//calcula una resta
int calculoResta (int x, int y)
{
	int tot;
	tot=x-y;
	return tot;
}

//calcula una division
int calculoDivision (int x, int y)
{
	int tot;
	if(y!=0){tot=x/y;}
	else{printf("No es posible dividir por 0\n");}
	return tot;
}

//calcula un promedio
float calcularPromedio(float *acumulador, float *contador)
{	float auxiliar;
	auxiliar=*acumulador / *contador;
	return auxiliar;
}

//pide una letra
int utn_getCaracter(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	char buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError!=NULL && minimo<= maximo && reintentos >=0)
	{
		do
		{
		printf("%s", mensaje);
		scanf("%c",&buffer);
		if(buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno=0;
		}
		else
		{
			printf("%s", mensajeError);
			reintentos--;
		}
		}while(reintentos>=0);
	}

return retorno;}

//ordena un array
int ordenarArrayInt(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador=0;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		do
		{
			flagSwap=0;
			for( i=0 ; i<limite - 1 ; i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

//muestra el array completo
int printArrayInt(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("\n Indice: %d - Valor: %d",i,pArray[i]);
		}
	}
	return retorno;
}

/*
 * \brief Solicita un entero al usuario y devuelve un resultado.
 * \param Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
*/
int getInts(char *mensaje)
{
	int aux;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d",&aux);
	return aux;
}
/*
 * \brief Solicita un flotante al usuario y devuelve un resultado.
 * \param Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
*/
float getFloat(char *mensaje)
{
	float aux;
	printf("%s",mensaje);
	scanf("%f",&aux);
	return aux;


	return 1;
}
/*
 * \brief Solicita un caracter al usuario y devuelve un resultado.
 * \param Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
*/
char getChar(char *mensaje)
{
	char aux;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&aux);
	return aux;
}

/*int printArrayChar(char* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("\n Indice: %d - Valor: %s",i,pArray[i]);
		}
	}
	return retorno;
}*/

/*
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
*/
int esNumerico(char str[])
{int i=0;
	while(str[i]!='\0')
	{
		if(str[i]<'0' || str[i]>'9')
		{	return 0;
			i++;}
	}

return 1;}

/*
 * \brief Verifica si el valor recibido solo tiene letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si es todo letras y 0 si no lo es
*/
int soloLetras(char str[])
{
	int i=0;
	while(str[i]!='\n')
	{
		if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A'|| str[i]>'A'))
		{
			return 0;
			i++;
		}
	}
return 1;}
/*
 * \brief Verifica si el valor recibido es alfanumerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es alfanumerico y 0 si no lo es
*/
int alfaNumerico(char str[])
{	int i=0;
	while(str[i]!='\0')
	{
		if(  (str[i]!=' ') && (str[i]<'a'||str[i]>'z') && (str[i]<'a' || str[i]>'A') && (str[i]<'0' || str[i]>'9')  )
		{
			return 0;
			i++;
		}
	}

return 1;}
/*
 * \brief Verifica si el valor recibido contiene + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene numeros, espacios y un guion
*/
int esTelefono(char str[])
{	int i=0;
	int contadorDeGuiones=0;
	while (str[i]!='\0')
	{
		if(  (str[i]!=' ')&&(str[i]<'0' || str[i]>'9')&&(str[i]!='-'))
		{
			return 0;
		}
		if(str[i]=='-')
		{
			contadorDeGuiones++;
		}
			i++;}
	if(contadorDeGuiones==1)
	{
		return 1;
	}
return 0;}

//calcula una multiplicacion
float calculoMultiplicarF (float x, float y)
{
	float tot;
	tot=x*y;
	return tot;
}

//calcula una suma
float calculoSumaF (float x, float y)
{
	float tot;
	tot=x+y;
	return tot;
}

//calcula una resta
float calculoRestaF (float x, float y)
{
	float tot;
	tot=x-y;
	return tot;
}

//calcula una division
float calculoDivisionF (float x, float y)
{
	float tot;
	if(y!=0){tot=x/y;}
	else{printf("No es posible dividir por 0\n");}
	return tot;
}

float factorialF(float x)
{
	int i;
	float aux;
	for(i=0;i<x;i++)
	{	aux=x*i;
	}
	return aux;
}
