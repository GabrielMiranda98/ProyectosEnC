#include "Productos.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

/** \brief Crea un empleado
 * \return auxP Employee*
 */
Productos* producto_new(void)
{		Productos* auxP;

	auxP=(Productos*)malloc(sizeof(Productos));

	return auxP;

}
/** \brief Crea un empleado con parametros
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldo char*
 * \return this Employee*
 */
Productos* producto_newParametros(char* id,char* fecha,char* codigo,char* cantidad,char* precio,char* cuit)
{
		Productos* auxP=NULL;
		auxP=producto_new();
		int idAux;
		int auxPrecio;
		if(auxP!=NULL)
		  {
				idAux = atoi(id);
				auxPrecio = atoi(precio);

			 auxP->id=idAux;
			  strcpy(auxP->fecha,fecha);
			  strcpy(auxP->codigo,codigo);
			  strcpy(auxP->cantidad,cantidad);
			  strcpy(auxP->cuit,cuit);

			 auxP->precio=auxPrecio;
		  }
		  return auxP;
		}


/** \brief Elimina un empleado
 * \param this Employee*
 * \return 0 ok -1 error
 */
int producto_delete(Productos* this)
{	int retorno=-1;

	if(this!=NULL)
	{retorno=0;
		free(this);
	}
	return retorno;
}
/** \brief Establece el ID de un empleado
 * \param contadorID int
 * \return numero de inicio 8
 */
static int contadorID = 0;
/** \brief Suma +1 el ID de un empleado
 * \param contadorID int
 * \return lo aumenta en 1
 */
int employee_automaticId()
{
	return contadorID++;
}
/** \brief Establece el ID de un empleado
 * \param this Employee*
 * \param id int
 * \return 0 ok -1 error
 */

int producto_setId(Productos* this,int id)
{
	int retorno = -1;

		if(this!=NULL && id>=0)
		{
			this->id = id;
			retorno = 0;
		}
		return retorno;
}
/** \brief Devuelve el ID de un empleado
 * \param this Employee*
 * \param id int*
 * \return 0 ok -1 error
 */
int producto_getId(Productos* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id>=0)
		{
			*id = this->id;
			retorno = 0;
		}
		return retorno;
}
/** \brief Establece el nombre de un empleado
 * \param this Employee*
 * \param nombre char*
 * \return 0 ok -1 error
 */

int producto_setFecha(Productos* this,char* fecha)
{
	int retorno = -1;
	if(this!=NULL && fecha!=NULL)
	{
		strncpy(this->fecha,fecha,FECHA_LEN);
	}

	return retorno;

}
/** \brief Devuelve el nombre de un empleado
 * \param this Employee*
 * \param nombre char*
 * \return 0 ok -1 error
 */
int producto_getFecha(Productos* this,char* fecha)
{
	int retorno = -1;
	if(this!=NULL&&fecha!=NULL)
	{
		retorno=0;
		strcpy(fecha,this->fecha);
	}
	return retorno;
}

int producto_setCuit(Productos* this,char* cuit)
{
	int retorno = -1;
	if(this!=NULL && cuit!=NULL&& isValidCUIT(cuit)==1)
	{
		strncpy(this->cuit,cuit,CUIT_LEN);
	}

	return retorno;

}
int producto_getCuit(Productos* this,char* cuit)
{
	int retorno = -1;
	if(this!=NULL&&cuit!=NULL)
	{
		retorno=0;
		strcpy(cuit,this->cuit);
	}
	return retorno;
}
/** \brief Establece las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int
 * \return 0 ok -1 error
 */
int producto_setCodigo(Productos* this,char* codigo)
{
	int retorno = -1;
	if(this!=NULL && codigo!=NULL)
	{
		strncpy(this->codigo,codigo,CODIGO_LEN);
	}

	return retorno;
}
/** \brief Devuelve las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return 0 ok -1 error
 */
int producto_getCodigo(Productos* this,char* codigo)
{		int retorno = -1;
		if(this!=NULL&&codigo!=NULL)
			{
				retorno=0;
				strcpy(codigo,this->codigo);
			}
return retorno;
}


/** \brief Establece las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int
 * \return 0 ok -1 error
 */
int producto_setCantidad(Productos* this,char* cantidad)
{
	int retorno = -1;
	if(this!=NULL && cantidad!=NULL)
	{
		strncpy(this->cantidad,cantidad,CANTIDAD_LEN);
	}

	return retorno;
}
/** \brief Devuelve las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return 0 ok -1 error
 */
int producto_getCantidad(Productos* this,char* cantidad)
{
	int retorno = -1;
		if(this!=NULL&&cantidad!=NULL)
		{
			retorno=0;
			strncpy(cantidad,this->cantidad,CANTIDAD_LEN);
		}
		return retorno;
}


/** \brief Establece el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int
 * \return 0 ok -1 error
 */
int producto_setPrecio(Productos* this,int precio)
{
	int retorno = -1;

			if(this!=NULL && precio>=0)
			{
				this->precio = precio;
				retorno = 0;
			}
			return retorno;
}

/** \brief Devuelve el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int*
 * \return 0 ok -1 error
 */
int producto_getPrecio(Productos* this,int* precio)
{
	int retorno = -1;

			if(this!=NULL && precio>=0)
			{
				*precio = this->precio;
				retorno = 0;
			}
			return retorno;
}
/*
int producto_map(void* p)
{
  int retorno = -1;
  int monto= 240, cantidadAux;
  char dias[50];

  Productos* movie;

  if(p != NULL){
    movie = (Productos*) p;
    producto_getCantidad(movie,dias);
    if(strcmp("Lunes",dias)==0&&strcmp("Martes",dias)==0&&strcmp("Miércoles",dias)==0){
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

*/




int ProductoVentasTotales(void* p){
  int retorno = -1;
  if(p != NULL){
    if(ll_isEmpty(p)==0){
        retorno = 1;
    }
  }
  return retorno;
}

int ProductoMayoresA10000(void* p){
  int retorno = -1;
  Productos* ent;
  if(p != NULL){
    ent = (Productos*) p;
    if((ent->precio) > 10000){
        retorno = 1;
    }
  }
  return retorno;
}

int ProductoMayoresA20000(void* p){
  int retorno = -1;
  Productos* ent;
  if(p != NULL){
    ent = (Productos*) p;
    if((ent->precio) > 20000){
        retorno = 1;
    }
  }
  return retorno;
}

int ProductoventasTVsLCD(void* p){
  int retorno = -1;
  Productos* ent;

  if(p != NULL){
    ent = (Productos*) p;
    if(strcmp(ent->codigo, "LCD_TV") == 0){
        retorno = 1;
    }
  }
  return retorno;
}
