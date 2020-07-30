#include "PrototipoTwo.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief Crea un nuevo prototipo
 * \return auxP Employee*
 */
PrototipoTwo* prototipoTwo_new(void)
{		PrototipoTwo* auxP;

	auxP=(PrototipoTwo*)malloc(sizeof(PrototipoTwo));

	return auxP;

}
/** \brief Crea un prototipo con parametros
 * \param primer_parametroStr char*
 * \param segundo_parametroStr char*
 * \param tercer_parametroStr char*
 * \param cuarto_parametroStr char*
 * \return this Prototipo*
 */
PrototipoTwo* prototipoTwo_newParametros(char* primer_parametroStrToInt,char* segundo_parametroStr,char* tercer_parametroStr)
{
	//primer_parametroStr
		PrototipoTwo* auxP=NULL;
		auxP=prototipoTwo_new();
		if(auxP!=NULL)
		  {
			  prototipoTwo_setPrimerParametro(auxP,atoi(primer_parametroStrToInt));
			  prototipoTwo_setSegundoParametro(auxP,segundo_parametroStr);
			  prototipoTwo_setTercerParametro(auxP,tercer_parametroStr);
		  }
		  return auxP;
		}


/** \brief Elimina un prototipo
 * \param this Prototipo*
 * \return 0 ok -1 error
 */
int prototipoTwo_delete(PrototipoTwo* this)
{	int retorno=-1;

	if(this!=NULL)
	{retorno=0;
		free(this);
	}
	return retorno;
}
/** \brief Establece el primer_parametro de un protipo
 * \param this Prototipo*
 * \param primer_parametro int
 * \return 0 ok -1 error
 */

int prototipoTwo_setPrimerParametro(PrototipoTwo* this,int primer_parametro)
{
	int retorno = -1;

		if(this!=NULL && primer_parametro>=0)
		{
			this->primer_parametro = primer_parametro;
			retorno = 0;
		}
		return retorno;
}
/** \brief Devuelve el primer_parametro de un protipo
 * \param this Prototipo*
 * \param primer_parametro int*
 * \return 0 ok -1 error
 */
int prototipoTwo_getPrimerParametro(PrototipoTwo* this,int* primer_parametro)
{
	int retorno = -1;

		if(this!=NULL && primer_parametro>=0)
		{
			*primer_parametro = this->primer_parametro;
			retorno = 0;
		}
		return retorno;
}
/** \brief Establece el segundo_parametro de un Prototipo
 * \param this Prototipo*
 * \param segundo_parametro char*
 * \return 0 ok -1 error
 */

int prototipoTwo_setSegundoParametro(PrototipoTwo* this,char* segundo_parametro)
{
	int retorno = -1;
	if(this!=NULL && segundo_parametro!=NULL)
	{
		strncpy(this->segundo_parametro,segundo_parametro,SEGUNDO_LEN2);
	}

	return retorno;

}
/** \brief Devuelve el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipoTwo_getSegundoParametro(PrototipoTwo* this,char* segundo_parametro)
{
	int retorno = -1;
	if(this!=NULL&&segundo_parametro!=NULL)
	{
		retorno=0;
		strcpy(segundo_parametro,this->segundo_parametro);
	}
	return retorno;
}
/** \brief Establece el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipoTwo_setTercerParametro(PrototipoTwo* this,char* tercer_parametro)
{
	int retorno = -1;
	if(this!=NULL && tercer_parametro!=NULL)
	{
		strncpy(this->tercer_parametro,tercer_parametro,TERCER_LEN2);
	}

	return retorno;
}
/** \brief Devuelve el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipoTwo_getTercerParametro(PrototipoTwo* this,char* tercer_parametro)
{		int retorno = -1;
		if(this!=NULL&&tercer_parametro!=NULL)
			{
				retorno=0;
				strcpy(tercer_parametro,this->tercer_parametro);
			}
return retorno;
}


/** \brief Establece el cuarto parametro del prototipo
 * \param this Prototipo*
 * \param cuarto_parametro char*
 * \return 0 ok -1 error
 */
int prototipoTwo_setCuartoParametro(PrototipoTwo* this,char* cuarto_parametro)
{
	int retorno = -1;
	if(this!=NULL && cuarto_parametro!=NULL)
	{
		strncpy(this->cuarto_parametro,cuarto_parametro,CUARTO_LEN2);
	}

	return retorno;
}
/** \brief Devuelve el cuarto_parametro de un Prototipo
 * \param this Prototipo*
 * \param cuarto_parametro char*
 * \return 0 ok -1 error
 */
int prototipoTwo_getCuartoParametro(PrototipoTwo* this,char* cuarto_parametro)
{
	int retorno = -1;
		if(this!=NULL&&cuarto_parametro!=NULL)
		{
			retorno=0;
			strncpy(cuarto_parametro,this->cuarto_parametro,CUARTO_LEN2);
		}
		return retorno;
}


int prototipoTwo_setQuintoParametro(PrototipoTwo* this,char* quinto_parametro)
{
	int retorno = -1;
	if(this!=NULL && quinto_parametro!=NULL)
	{
		strncpy(this->quinto_parametro,quinto_parametro,QUINTO_LEN2);
	}

	return retorno;

}
/** \brief Devuelve el quinto_parametro de un Prototipo
 * \param this Prototipo*
 * \param quinto_parametro char*
 * \return 0 ok -1 error
 */
int prototipoTwo_getQuintoParametro(PrototipoTwo* this,char* quinto_parametro)
{
	int retorno = -1;
	if(this!=NULL&&quinto_parametro!=NULL)
	{
		retorno=0;
		strcpy(quinto_parametro,this->quinto_parametro);
	}
	return retorno;
}
/*EJEMPLO
 *	CALCULO LA COLUMNA EXTRA MONTO
 *  VALOR DE ENTRADAS CLASIFICADA POR DIAS
 *
*/
int prototipoTwo_map(void* p)
{

  int retorno = -1;
  int monto=240, cantidadAux;
  int parametroAux;


  PrototipoTwo* aux;

  if(p != NULL){
    aux = (PrototipoTwo*) p;
    prototipo_getPrimerParametro(aux,parametroAux); //PARAMETRO Y AUXILIAR A CAMBIAR
    if(strcmp("Lunes",parametroAux)==0&&strcmp("Martes",parametroAux)==0&&strcmp("Miércoles",parametroAux)==0){
      monto= (cantidadAux)*240 ;
    }else if(cantidadAux>3){
      monto = (cantidadAux)* (240*0.90);
    }else{
      monto = (cantidadAux)*360;
    }
    retorno = 0;
  }
  return retorno;
}


/*
 * Ejemplo filter
*/

int prototipoTwoVentasTotales(void* p){
  int retorno = -1;
  if(p != NULL){
    if(ll_isEmpty(p)==0){
        retorno = 1;
    }
  }
  return retorno;
}
int prototipoTwoMayoresAx(void* p){
  int retorno = -1;
  PrototipoTwo* ent;
  if(p != NULL){
    ent = (PrototipoTwo*) p;
    if((ent->primer_parametro) > 1){ //a criterio de lo que pide el cliente
        retorno = 1;
    }
  }
  return retorno;
}
int prototipoTwoMenoresyoresAx(void* p){
  int retorno = -1;
  PrototipoTwo* ent;
  if(p != NULL){
    ent = (PrototipoTwo*) p;
    //get del parametro a recibir
    if((ent->primer_parametro) < 2){ //a criterio de lo que pide el cliente
        retorno = 1;
    }
  }
  return retorno;
}
int PrototipoTwoMayorCantidadNombre(void* p){
  int retorno = -1;
  PrototipoTwo* ent;

  if(p != NULL){
    ent = (PrototipoTwo*) p;
    if(strcmp(ent->quinto_parametro, "A MODIFICAR // LCD") == 0){
        retorno = 1;
    }
  }
  return retorno;
}
