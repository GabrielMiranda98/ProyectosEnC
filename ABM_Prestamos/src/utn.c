/*
 * utn.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int esNumericade(char*cadena)
{
	int retorno=1;
	int i=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0' || cadena[i] > '9')
			{
				retorno=0;
				break;
			}
		}


	}
return retorno;
}
int myGetse(char* cadena, int longitud)
{
	if(cadena!=NULL && longitud>0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		return 0;
	}
		return -1;
}
static int getIntsed(int*pResultado)
{	int retorno=-1;
	char buffer[64];
	if(pResultado!=NULL)
	{
		if(myGetse(buffer,sizeof(buffer))==0 && esNumericade(buffer))
		{
			*pResultado = atoi(buffer);
			retorno=0;
		}
	}
return retorno;}
int utn_getNumero(int* pResultado,char * mensaje, char * mensajeError , int minimo , int maximo , int reintentos)
{
	int bufferInt;
	int retorno=-1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getIntsed(&bufferInt)==0)
		{
			if(bufferInt>= minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				retorno=0;
				break;
			}
		}
		else{
		printf("%s",mensajeError);
		reintentos--;
		printf("Reintentos[%d]",reintentos);

}}

return retorno;}
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s",msgError);
            printf("Reintentos[%d]",*reintentos);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr))
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidName(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidSignedNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidSignedNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='+' && stringRecibido[0]!='-'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTelephone(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidTelephone(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    maxSize=11;
    minSize=8;
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidDNI(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidDNI(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esCuil(char* str);
static int getCuil(char* pResultado, int longitud);
static int getString5(char* cadena, int longitud);

static int getString5(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096]; // *

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

static int esCuil(char* str)
{
    int i=0;
    int contadorGuiones = 0;
    int flag = 1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i]>'9'))
        {
            flag = 0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones == 2)
    {
        flag =1;
    }else
    {
        flag =0;
    }

    return flag;
}
static int getCuil(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString5(buffer,sizeof(buffer))==0 &&
    		esCuil(buffer) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getCuil(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getCuil(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidEmail(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);

                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidEmail(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidTexto(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidAlphanumeric(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar[256];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,1,3,&reintentos,bufferChar))
            {
                if(isValidChar(bufferChar[0])==1)
                {
                    printf("OK");
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidChar(char charRecibido)
{
    int retorno=1;
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=0;
    return retorno;
}
int utn_getStringNumero(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    printf("Reintentos[%d]",reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidNumeroArray(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
