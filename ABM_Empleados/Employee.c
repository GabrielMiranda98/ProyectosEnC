#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

#include "utn.h"

/** \brief Crea un empleado
 * \return auxP Employee*
 */
Employee* employee_new(void)
{		Employee* auxP;

	auxP=(Employee*)malloc(sizeof(Employee));

	return auxP;

}
/** \brief Crea un empleado con parametros
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldo char*
 * \return this Employee*
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* auxP=NULL;
		auxP=employee_new();
		int idAux;
		int horasTrabajadasAux;
		int sueldoAux;
		  if(auxP!=NULL)
		  {
			  idAux = atoi(idStr);
			  horasTrabajadasAux = atoi(horasTrabajadasStr);
			  sueldoAux = atoi(sueldo);

			  auxP->id=idAux;
			  strcpy(auxP->nombre,nombreStr);
			  auxP->horasTrabajadas=horasTrabajadasAux;
			  auxP->sueldo=sueldoAux;

		  }
		  return auxP;
		}

/** \brief Elimina un empleado
 * \param this Employee*
 * \return 0 todo bien -1 error
 */
int employee_delete(Employee* this)
{	int retorno=-1;

	if(this!=NULL)
	{retorno=0;
		free(this);
	}
	return retorno;
}
/** \brief Establece el ID de un empleado
 * \param contadorID int
 * \return numero de inicio 1001
 */
static int contadorID = 1001;
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
 * \return 0 todo bien -1 error
 */
int employee_setId(Employee* this,int id)
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
 * \return 0 todo bien -1 error
 */
int employee_getId(Employee* this,int* id)
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
 * \return 0 todo bien -1 error
 */
int employee_setNombre(Employee* this,char* nombre)
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
 * \return 0 todo bien -1 error
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL&&nombre!=NULL)
	{
		retorno=0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}
/** \brief Establece las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int
 * \return 0 todo bien -1 error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

		if(this!=NULL && horasTrabajadas>0)
		{
			this->horasTrabajadas=horasTrabajadas;
			retorno = 0;
		}

		return retorno;
}

/** \brief Devuelve las horas trabajadas de un empleado
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return 0 todo bien -1 error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

			if(this!=NULL && horasTrabajadas>0)
			{
				*horasTrabajadas = this->horasTrabajadas;
				retorno = 0;
			}
			return retorno;
}
/** \brief Establece el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int
 * \return 0 todo bien -1 error
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		retorno = 0;
	}

	return retorno;
}

/** \brief Devuelve el sueldo de un empleado
 * \param this Employee*
 * \param sueldo int*
 * \return 0 todo bien -1 error
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>0)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
/** \brief Compara dos empleados por ID
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 */
int employeeSortById(void* empleadoA, void* empleadoB){
    int retorno = -1;
    int id1;
    int id2;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        employee_getId(empA,&id1);
        employee_getId(empB,&id2);


        if(( id1)<(id2)){
            retorno = 1 ;
        }else if((id1)>(id2)){
            retorno = -1 ;
        }else if((id1)==(id2)){
            retorno = 0;
        }
    }
    return retorno;
}
/** \brief Compara dos empleados por nombre
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 */
int employeeSortByName(void* empleadoA, void* empleadoB){
    int retorno = 0;
    char n1[50];
    char n2[50];


    if(empleadoA !=NULL && empleadoB !=NULL){
        employee_getNombre(empleadoA,n1);
        employee_getNombre(empleadoB,n2);
         if(strcmp(n1, n2)>0)
         {
        	 retorno=1;
         }
         else if(strcmp(n2, n1)>0)
         {
        	 retorno=-1;
         }
    }

    return retorno;
}
/** \brief Compara dos empleados por horas trabajadas
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 */
int employeeSortByHours(void* empleadoA, void* empleadoB){
    int retorno = -1;
    int h1;
    int h2;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
           employee_getHorasTrabajadas(empA,&h1);
           employee_getHorasTrabajadas(empB,&h2);
                if((h1)<(h2)){
            retorno = 1 ;
        }else if((h1)>(h2)){
            retorno = -1 ;
        }else if((h1)==(h2)){
            retorno = 0;
        }
    }
    return retorno;
}
/** \brief Compara dos empleados por sueldo
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int
 */
int employeeSortBySalary(void* empleadoA, void* empleadoB){
    int retorno = -1;
    int s1;
    int s2;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        employee_getSueldo(empA,&s1);
        employee_getSueldo(empB,&s2);
        if((s1)<(s2)){
            retorno = 1 ;
        }else if((s1)>(s2)){
            retorno = -1 ;
        }else if((s1)==(s2)){
            retorno = 0;
        }
    }
    return retorno;
}
