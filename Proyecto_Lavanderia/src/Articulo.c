#include "Articulo.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief Crea un nuevo prototipo
 * \return auxP Employee*
 */
Articulo* prototipo_new(void)
{		Articulo* auxP;

	auxP=(Articulo*)malloc(sizeof(Articulo));

	return auxP;

}
/** \brief Crea un prototipo con parametros
 * \param primer_parametroStr char*
 * \param segundo_parametroStr char*
 * \param tercer_parametroStr char*
 * \param cuarto_parametroStr char*
 * \return this Prototipo*
 */
Articulo* prototipo_newParametros(char* primer_parametroStrToInt,char* segundo_parametroStr,char* tercer_parametroStr,
		char* cuarto_parametroStr,char* quinto_parametroStr)
{
		Articulo* auxP=NULL;
		auxP=prototipo_new();
		if(auxP!=NULL)
		  {
			prototipo_setPrimerParametro(auxP,atoi(primer_parametroStrToInt));
			prototipo_setSegundoParametro(auxP,segundo_parametroStr);
			prototipo_setTercerParametro(auxP,tercer_parametroStr);
			prototipo_setCuartoParametro(auxP,atoi(cuarto_parametroStr));
			prototipo_setQuintoParametro(auxP,atoi(quinto_parametroStr));

		  }
		  return auxP;
		}

/** \brief Elimina un prototipo
 * \param this Prototipo*
 * \return 0 ok -1 error
 */
int prototipo_delete(Articulo* this)
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
int prototipo_setPrimerParametro(Articulo* this,int primer_parametro)
{
	int retorno = -1;

		if(this!=NULL && primer_parametro>=0)
		{
			this->id = primer_parametro;
			retorno = 0;
		}
		return retorno;
}
/** \brief Devuelve el primer_parametro de un protipo
 * \param this Prototipo*
 * \param primer_parametro int*
 * \return 0 ok -1 error
 */
int prototipo_getPrimerParametro(Articulo* this,int* primer_parametro)
{
	int retorno = -1;

		if(this!=NULL && primer_parametro>=0)
		{
			*primer_parametro = this->id;
			retorno = 0;
		}
		return retorno;
}
/** \brief Establece el segundo_parametro de un Prototipo
 * \param this Prototipo*
 * \param segundo_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_setCuartoParametro(Articulo* this,int cuarto_parametro)
{
	int retorno = -1;

		if(this!=NULL && cuarto_parametro>=0)
		{
			this->precio = cuarto_parametro;
			retorno = 0;
		}
		return retorno;
}
/** \brief Devuelve el primer_parametro de un protipo
 * \param this Prototipo*
 * \param primer_parametro int*
 * \return 0 ok -1 error
 */
int prototipo_getCuartoParametro(Articulo* this,int* cuarto_parametro)
{
	int retorno = -1;

		if(this!=NULL && cuarto_parametro>=0)
		{
			*cuarto_parametro = this->precio;
			retorno = 0;
		}
		return retorno;
}
int prototipo_setQuintoParametro(Articulo* this,int quinto_parametro){
	int retorno = -1;

		if(this!=NULL && quinto_parametro>=0)
		{
			this->rubroID = quinto_parametro;
			retorno = 0;
		}
		return retorno;
}
int prototipo_getQuintoParametro(Articulo* this,int* quinto_parametro){
	int retorno = -1;

		if(this!=NULL && quinto_parametro>=0)
		{
			*quinto_parametro = this->rubroID;
			retorno = 0;
		}
		return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int prototipo_setSegundoParametro(Articulo* this,char* segundo_parametro)
{
	int retorno = -1;
	if(this!=NULL && segundo_parametro!=NULL)
	{
		strncpy(this->articulo,segundo_parametro,SEGUNDO_LEN);
	}

	return retorno;

}
/** \brief Devuelve el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_getSegundoParametro(Articulo* this,char* segundo_parametro)
{
	int retorno = -1;
	if(this!=NULL&&segundo_parametro!=NULL)
	{
		retorno=0;
		strcpy(segundo_parametro,this->articulo);
	}
	return retorno;
}
/** \brief Establece el tercer_parametro de un Prototipo
 * \param this Prototipo*
 * \param tercer_parametro char*
 * \return 0 ok -1 error
 */
int prototipo_setTercerParametro(Articulo* this,char* tercer_parametro)
{
	int retorno = -1;
	if(this!=NULL && tercer_parametro!=NULL)
	{
		strncpy(this->medidas,tercer_parametro,TERCER_LEN);
	}

	return retorno;
}
int prototipo_getTercerParametro(Articulo* this,char* tercer_parametro)
{		int retorno = -1;
		if(this!=NULL&&tercer_parametro!=NULL)
			{
				retorno=0;
				strcpy(tercer_parametro,this->medidas);
			}
return retorno;
}
int ArticuloSortByName(void* a, void* b){
    int retorno = 0;
    char n1[50];
    char n2[50];
    	prototipo_getSegundoParametro(a,n1);
    	prototipo_getSegundoParametro(b,n2);
         if(strcmp(n1, n2)>0)
         {
        	 retorno=1;
         }
    return retorno;
}
int prototipo_map(void* p)
{
  int retorno = -1;
  int  cantidadAux=0;
  int rubro;
  Articulo* art;
  if(p != NULL)
{
    art = (Articulo*) p;
    prototipo_getQuintoParametro(art,&rubro);
    prototipo_getCuartoParametro(art,&cantidadAux);
    if(rubro==1 && cantidadAux>=120)
    {cantidadAux=(cantidadAux)*0.80;}
    else if(rubro==2&&cantidadAux<=200)
    {cantidadAux=(cantidadAux)*0.90;}
	prototipo_setCuartoParametro(art,cantidadAux);
    retorno = 0;

}
  return retorno;
}
int prototipoMayora100(void* p){
  int retorno = -1, auxPrecio;
  Articulo* ent;
  if(p != NULL){
    ent = (Articulo*) p;
    prototipo_getCuartoParametro(ent,&auxPrecio);
    if((auxPrecio) > 100){
        retorno = 1;
    }
  }
  return retorno;
}
int PrototipoMayorCantidadRubro(void* p){
  int retorno = -1;
  int rubro;
  Articulo* ent;
  if(p != NULL){
    ent = (Articulo*) p;
    prototipo_getQuintoParametro(ent,&rubro);
    if(rubro==1){
        retorno = 1;
    }
  }
  return retorno;
}
