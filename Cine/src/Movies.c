#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Movies.h"
#include "utn.h"

/** \brief Crea un empleado
 * \return auxP Employee*
 */
Movies* movies_new(void)
{		Movies* auxP;

	auxP=(Movies*)malloc(sizeof(Movies));

	return auxP;

}
/** \brief Crea un empleado con parametros
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldo char*
 * \return this Employee*
 */
Movies* movies_newParametros(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr,char* cantidadEntradas)
{
		Movies* auxP=NULL;
		auxP=movies_new();
		int idAux;
		int auxDia;
		int auxSala;
		int auxCantidadEntradas;
		char auxDiasThis[60];
		if(auxP!=NULL)
		  {
			  idAux = atoi(idStr);
			  auxDia = atoi(diaStr);
			  auxSala = atoi(salaStr);
			  auxCantidadEntradas = atoi(cantidadEntradas);
	    	   switch(auxDia)
	    				   {
	    				   	   case 0:
	    				   		   strcpy(auxDiasThis,"Domingo");
	    				   		   break;

	    				   	   case 1:
	    				   		   strcpy(auxDiasThis,"Lunes");

	    				   		   break;
	    				   	   case 2:
	    				   		   strcpy(auxDiasThis,"Martes");

	    				   		   break;
	    				   	   case 3:
	    				   		   strcpy(auxDiasThis,"Miercoles");

	    				   		   break;
	    				   	   case 4:
	    				   		   strcpy(auxDiasThis,"Jueves");

	    				   		   break;
	    				   	   case 5:
	    				   		   strcpy(auxDiasThis,"Viernes");

	    				   		   break;
	    				   	   case 6:
	    				   		   strcpy(auxDiasThis,"Sabado");
	    				   		   break;
	    				   }
			  strcpy(auxP->nombre,nombreStr);
			  auxP->id=idAux;
			  auxP->dia=auxDia;
			  strcpy(auxP->horario,horarioStr);
			  strcpy(auxP->dias,auxDiasThis);
			  auxP->sala=auxSala;
			  auxP->cantidadEntradas=auxCantidadEntradas;

		  }
		  return auxP;
		}


/** \brief Elimina un empleado
 * \param this Employee*
 * \return 0 ok -1 error
 */
int movies_delete(Movies* this)
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
static int contadorID = 8;
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

int movies_setId(Movies* this,int id)
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
int movies_getId(Movies* this,int* id)
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

int movies_setNombre(Movies* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL&& isValidName(nombre)==1)
	{
		strncpy(this->nombre,nombre,NOMBRE_LEN);
	}

	return retorno;

}
/** \brief Devuelve el nombre de un empleado
 * \param this Employee*
 * \param nombre char*
 * \return 0 ok -1 error
 */
int movies_getNombre(Movies* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL&&nombre!=NULL)
	{
		retorno=0;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}

/** \brief Establece las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int
 * \return 0 ok -1 error
 */
int movies_setDiaInt(Movies* this,int dia)
{
	int retorno = -1;

		if(this!=NULL && dia>0)
		{
			this->dia=dia;
			retorno = 0;
		}

		return retorno;
}
/** \brief Devuelve las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return 0 ok -1 error
 */
int movies_getDiaInt(Movies* this,int* dia)
{
	int retorno = -1;

			if(this!=NULL && dia>0)
			{
				*dia = this->dia;
				retorno = 0;
			}
			return retorno;
}


/** \brief Establece las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int
 * \return 0 ok -1 error
 */
int movies_setDiaChar(Movies* this,char* dias)
{
	int retorno = -1;
	if(this!=NULL && dias!=NULL&& isValidName(dias)==1)
	{
		strncpy(this->dias,dias,DIAS_LEN);
	}

	return retorno;
}
/** \brief Devuelve las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return 0 ok -1 error
 */
int movies_getDiaChar(Movies* this,char* dias)
{
	int retorno = -1;
		if(this!=NULL&&dias!=NULL)
		{
			retorno=0;
			strncpy(dias,this->dias,DIAS_LEN);
		}
		return retorno;
}


/** \brief Establece el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int
 * \return 0 ok -1 error
 */
int movies_setHorario(Movies* this,char* horario)
{
	int retorno = -1;
	if(this!=NULL && horario!=NULL&& isValidHora(horario)==1)
	{
		strncpy(this->horario,horario,sizeof(this->horario));
	}

	return retorno;
}

/** \brief Devuelve el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int*
 * \return 0 ok -1 error
 */
int movies_getHorario(Movies* this,char* horario)
{
	int retorno = -1;
	if(this!=NULL&&horario!=NULL)
	{
		retorno=0;
		strncpy(horario,this->horario,HORARIO_LEN);
	}
	return retorno;
}
/** \brief Establece el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int
 * \return 0 ok -1 error
 */

int movies_setsala(Movies* this,int sala)
{
	int retorno = -1;

	if(this!=NULL && sala>0)
	{
		this->sala=sala;
		retorno = 0;
	}

	return retorno;
}
/** \brief Devuelve el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int*
 * \return 0 ok -1 error
 */
int movies_getsala(Movies* this,int* sala)
{
	int retorno = -1;

	if(this!=NULL && sala>0)
	{
		*sala = this->sala;
		retorno = 0;
	}
	return retorno;
}

/** \brief Establece el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int
 * \return 0 ok -1 error
 */
int movies_setcantidadEntradas(Movies* this,int cantidadEntradas)
{
	int retorno = -1;

	if(this!=NULL && cantidadEntradas>0)
	{
		this->cantidadEntradas=cantidadEntradas;
		retorno = 0;
	}

	return retorno;
}
/** \brief Devuelve el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int*
 * \return 0 ok -1 error
 */
int movies_getcantidadEntradas(Movies* this,int* cantidadEntradas)
{
	int retorno = -1;

	if(this!=NULL && cantidadEntradas>0)
	{
		*cantidadEntradas = this->cantidadEntradas;
		retorno = 0;
	}
	return retorno;
}


/** \brief Establece el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int
 * \return 0 ok -1 error
 */
int movies_setmontoFacturado(Movies* this,int montoFacturado)
{
	int retorno = -1;

	if(this!=NULL && montoFacturado>0)
	{
		this->montoFacturado=montoFacturado;
		retorno = 0;
	}

	return retorno;
}
/** \brief Devuelve el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int*
 * \return 0 ok -1 error
 */
int movies_getmontoFacturado(Movies* this,int* montoFacturado)
{
	int retorno = -1;

	if(this!=NULL && montoFacturado>0)
	{
		*montoFacturado = this->montoFacturado;
		retorno = 0;
	}
	return retorno;
}


int movieMapMontofacturado(void* p)
{
  int retorno = -1;
  int monto= 240, cantidadAux;
  char dias[50];

  Movies* movie;

  if(p != NULL){
    movie = (Movies*) p;
    movies_getDiaChar(movie,dias);
    movies_getcantidadEntradas(movie,&cantidadAux);
    if(strcmp("Lunes",dias)==0&&strcmp("Martes",dias)==0&&strcmp("Miércoles",dias)==0){
      monto= (cantidadAux)*240 ;
    }else if(cantidadAux>3){
      monto = (cantidadAux)* (240*0.90);
    }else{
      monto = (cantidadAux)*360;
    }
    movies_setmontoFacturado(movie, monto);
    retorno = 0;
  }
  return retorno;
}

int movieFilterSala1(void* p)
{
    int retorno = 0;
    Movies* movie;

    if(p != NULL)
    {
        movie = (Movies*) p;
        if(movie->sala==1)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movieFilterSala2(void* p)
{
    int retorno = 0;
    Movies* movie;

    if(p != NULL)
    {
        movie = (Movies*) p;
        if(movie->sala==2)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movieFilterSala3(void* p)
{
    int retorno = 0;
    Movies* movie;

    if(p != NULL)
    {
        movie = (Movies*) p;
        if(movie->sala==3)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movieFilterSala4(void* p)
{
    int retorno = 0;
    Movies* movie;

    if(p != NULL)
    {
        movie = (Movies*) p;
        if(movie->sala==4)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movieFilterSala5(void* p)
{
    int retorno = 0;
    Movies* movie;

    if(p != NULL)
    {
        movie = (Movies*) p;
        if(movie->sala==5)
        {
            retorno = 1;
        }
    }
    return retorno;
}

