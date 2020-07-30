#include "Prototipo.h"

#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

/** \brief Crea un nuevo prototipo
 * \return auxP Employee*
 */
Mensaje* prototipo_new(void)
{		Mensaje* auxP;

	auxP=(Mensaje*)malloc(sizeof(Mensaje));

	return auxP;

}
/** \brief Crea un prototipo con parametros
 * \param primer_parametroStr char*
 * \param segundo_parametroStr char*
 * \param tercer_parametroStr char*
 * \param cuarto_parametroStr char*
 * \return this Prototipo*
 */
Mensaje* prototipo_newParametros(char* primer_parametroStrToInt,char* segundo_parametroStr,char* tercer_parametroStr,char* cuarto_parametroStr)
{
	//primer_parametroStr
		Mensaje* auxP=NULL;
		auxP=prototipo_new();
		if(auxP!=NULL)
		  {
			  prototipo_setPrimerParametro(auxP,atoi(primer_parametroStrToInt));
			  prototipo_setSegundoParametro(auxP,segundo_parametroStr);
			  prototipo_setTercerParametro(auxP,tercer_parametroStr);
			  prototipo_setCuartoParametro(auxP,cuarto_parametroStr);
		  }
		  return auxP;
		}


/** \brief Elimina un prototipo
 * \param this Prototipo*
 * \return 0 ok -1 error
 */
int prototipo_delete(Mensaje* this)
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

int prototipo_setPrimerParametro(Mensaje* this,int primer_parametro)
{
	int retorno = -1;

		if(this!=NULL && primer_parametro>=0)
		{
			this->id_mensaje = primer_parametro;
			retorno = 0;
		}
		return retorno;
}
/** \brief Devuelve el primer_parametro de un protipo
 * \param this Prototipo*
 * \param primer_parametro int*
 * \return 0 ok -1 error
 */
int prototipo_getPrimerParametro(Mensaje* this,int* primer_parametro)
{
	int retorno = -1;

		if(this!=NULL && primer_parametro>=0)
		{
			*primer_parametro = this->id_mensaje;
			retorno = 0;
		}
		return retorno;
}
/** \brief Establece el segundo_parametro de un Prototipo
 * \param this Prototipo*
 * \param segundo_parametro char*
 * \return 0 ok -1 error
 */

int prototipo_setSegundoParametro(Mensaje* this,char* segundo_parametro)
{
	int retorno = -1;
	if(this!=NULL && segundo_parametro!=NULL)
	{
		strncpy(this->idUsuario,segundo_parametro,SEGUNDO_LEN);
	}

	return retorno;

}
/** \brief Devuelve el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_getSegundoParametro(Mensaje* this,char* segundo_parametro)
{
	int retorno = -1;
	if(this!=NULL&&segundo_parametro!=NULL)
	{
		retorno=0;
		strcpy(segundo_parametro,this->idUsuario);
	}
	return retorno;
}
/** \brief Establece el quinto_parametro de un Prototipo
 * \param this Prototipo*
 * \param quinto_parametro char*
 * \return 0 ok -1 error
 */

/** \brief Establece el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_setTercerParametro(Mensaje* this,char* tercer_parametro)
{
	int retorno = -1;
	if(this!=NULL && tercer_parametro!=NULL)
	{
		strncpy(this->Followers,tercer_parametro,TERCER_LEN);
	}

	return retorno;
}
/** \brief Devuelve el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_getTercerParametro(Mensaje* this,char* tercer_parametro)
{		int retorno = -1;
		if(this!=NULL&&tercer_parametro!=NULL)
			{
				retorno=0;
				strcpy(tercer_parametro,this->Followers);
			}
return retorno;
}


/** \brief Establece el cuarto parametro del prototipo
 * \param this Prototipo*
 * \param cuarto_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_setCuartoParametro(Mensaje* this,char* cuarto_parametro)
{
	int retorno = -1;
	if(this!=NULL && cuarto_parametro!=NULL)
	{
		strncpy(this->mensaje,cuarto_parametro,CUARTO_LEN);
	}

	return retorno;
}
/** \brief Devuelve el cuarto_parametro de un Prototipo
 * \param this Prototipo*
 * \param cuarto_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_getCuartoParametro(Mensaje* this,char* cuarto_parametro)
{
	int retorno = -1;
		if(this!=NULL&&cuarto_parametro!=NULL)
		{
			retorno=0;
			strncpy(cuarto_parametro,this->mensaje,CUARTO_LEN);
		}
		return retorno;
}

/*
int prototipo_map(void* p)
{
EJEMPLO
 *	CALCULO LA COLUMNA EXTRA MONTO
 *  VALOR DE ENTRADAS CLASIFICADA POR DIAS
 *

  int retorno = -1;
  int monto=240, cantidadAux;
  int parametroAux;


  Mensaje* aux;

  if(p != NULL){
    aux = (Mensaje*) p;
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



 * Ejemplo filter


int prototipoVentasTotales(void* p){
  int retorno = -1;
  if(p != NULL){
    if(ll_isEmpty(p)==0){
        retorno = 1;
    }
  }
  return retorno;
}

int prototipoMayoresAx(void* p){
  int retorno = -1;
  Mensaje* ent;
  if(p != NULL){
    ent = (Mensaje*) p;
    if((ent->id_mensaje) > 1){ //a criterio de lo que pide el cliente
        retorno = 1;
    }
  }
  return retorno;
}
int prototipoMenoresyoresAx(void* p){
  int retorno = -1;
  Mensaje* ent;
  if(p != NULL){
    ent = (Mensaje*) p;
    //get del parametro a recibir
    if((ent->id_mensaje) < 2){ //a criterio de lo que pide el cliente
        retorno = 1;
    }
  }
  return retorno;
}

int PrototipoMayorCantidadNombre(void* p){
  int retorno = -1;
  Mensaje* ent;

  if(p != NULL){
    ent = (Mensaje*) p;
    if(strcmp(ent->quinto_parametro, "A MODIFICAR // LCD") == 0){
        retorno = 1;
    }
  }
  return retorno;
}

*/
