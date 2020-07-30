#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
int controller_menu()
{
    int option = -1;
        printf("\n\t -Trabajo Practico N°3: LinkedList- \n\t\tGabriel Miranda \n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario). \n");
        printf("10. Salir \n");
        utn_getNumero(&option,"\nIngrese una opcion:\n"
        	    			,"\nERROR ingrese una opcion valida\n",1,10,3);

        return option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
	    int crear = 2;
	    FILE* listaFT;
	    if((listaFT=fopen(path, "r+")) == NULL)
	    {
	        printf("No se ha encontrado el archivo. ");
	        utn_getNumero(&crear,"\nDesea crear un archivo?  1-Si 2-No\n","\nError, opcion no valida\n",1,2,3);
	        if(crear == 1)
	        {
	            if ((listaFT=fopen(path,"w+"))==NULL)
	            {
	                printf("Error, no se ha podido abrir el archivo.\n");
	            }
	            else
	            {
	                printf("Archivo creado. ");
	                retorno=0;
	            }
	        }
	        else
	        {
	          printf("Volviendo al menu\n");
	        }
	    }
	    else
	    {   printf("Archivo encontrado y cargado. ");
	        parser_EmployeeFromText(listaFT, pArrayListEmployee);
	        retorno=0;
	    }
	    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
			int retorno = -1;
		    int crear = 2;
		    FILE*listaFB;
		    if((listaFB=fopen(path, "rb+")) == NULL)
		    {  printf("No se ha encontrado el archivo. ");
		       utn_getNumero(&crear,"\nDesea crear un archivo?  1-Si 2-No\n","\nError, opcion no valida\n",1,2,3);
		        if(crear == 1)
		        {       if ((listaFB=fopen(path,"wb+"))==NULL)
		        		{
		                printf("Error, no se ha podido abrir el archivo.\n");
		        		}
		        		else
		        		{
		                printf("Archivo creado. ");
		                retorno=0;
		        		}
		        }
		        else
		        	{
		            printf("Volviendo al menu\n");
		        	}
		    }
		    else
		    {   printf("Archivo encontrado y cargado. ");
		        parser_EmployeeFromBinary(listaFB, pArrayListEmployee);
		    }
return retorno;}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
		Employee* auxP;
		int retorno=-1;
		int auxId=0;
		char auxN[40];
		int auxS;
		int auxH;
		char idStr[10], nombreStr[100], horasStr[9], sueldoStr[20];
		if(pArrayListEmployee != NULL)
			{

				utn_getName("\nIngrese el nombre del empleado:\n","\nError\n",0,30,3,auxN);
				utn_getUnsignedInt("\nIngrese las horas trabajadas:","\nError",1,50,1,5000,3,&auxH);
				utn_getUnsignedInt("\nIngrese el sueldo:","\nError",1,30,1,100000,3,&auxS);
				auxId=employee_automaticId();

					sprintf(horasStr,"%d",auxH);
					sprintf(sueldoStr,"%d",auxS);
					sprintf(idStr,"%d",auxId);
					strcpy(nombreStr,auxN);

					auxP = employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);
					if(!ll_add(pArrayListEmployee,auxP))
					{
						printf("\tID\t\tNOMBRE\t\tHORAS TRABAJADAS\t\tSUELDO\n");
						printf("%10s %19s %20s %25s\n",idStr,nombreStr,horasStr,sueldoStr);
						retorno = 0;
						printf("\nALTA EXITOSA\n");

					}
					else
					{
						printf("\nALTA DENEGADA\n");
					}

				}
				else
				{
					printf("\nERROR\n");
				}

		  return retorno;	}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

		int idM;
	    int option;
	    int seguir = 2;
	    Employee* this;
	    char auxN[128];
	    int auxH;
	    int auxS;
	    int i;
	    int retorno=-1;
	    int auxIdThis, auxHsThis,auxSuThis;
	    				char auxNomThis[50];
	    if(pArrayListEmployee!=NULL)
	    {
			if(utn_getNumero(&idM,"\nIngrese ID del empleado a modificar: \n",
								"\nERROR OPCION NO VALIDA\n",0,ll_len(pArrayListEmployee),3)==0)
			{

			for(i=0; i<ll_len(pArrayListEmployee); i++){
				this = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getHorasTrabajadas(this,&auxHsThis);
			    employee_getId(this,&auxIdThis);
				employee_getNombre(this,auxNomThis);
				employee_getSueldo(this,&auxSuThis);
				if(idM == auxIdThis){
					printf("\tID\t\tNOMBRE\t\tHORAS TRABAJADAS\t\tSUELDO\n");
					printf("%10d %19s %20d %25d\n", auxIdThis,auxNomThis,auxHsThis,auxSuThis);
				do{
					utn_getNumero(&option,"\nIngrese dato a modificar:\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n4- Cancelar\n",
							"\nERROR OPCION NO VALIDA\n",1,4,3);

					switch(option)
					{
					case 1:retorno=0;
						utn_getName("\nIngrese el nombre del empleado:\n","\nError\n",0,30,3,auxN);
						employee_setNombre(this, auxN);
						printf("Desea continuar modificando al mismo empleado? ");
						utn_getNumero(&seguir,"\nDesea seguir modificando al mismo empleado? 1-SI \t2-NO: \n",
											"\nERROR OPCION NO VALIDA\n",1,2,3);
						if(seguir == 2){break;}
						break;
					case 2: retorno=0;
						utn_getUnsignedInt("\nIngrese las horas trabajadas:","\nError",1,50,1,5000,3,&auxH);
						employee_setHorasTrabajadas(this, auxH);
						utn_getNumero(&seguir,"\nDesea seguir modificando al mismo empleado? 1-SI \t2-NO: \n",
											"\nERROR OPCION NO VALIDA\n",1,2,3);
						if(seguir == 2){break;}
						break;
					case 3: retorno=0;
						utn_getUnsignedInt("\nIngrese el sueldo:","\nError",1,30,1,100000,3,&auxS);
						employee_setSueldo(this, auxS);
						utn_getNumero(&seguir,"\nDesea seguir modificando al mismo empleado? 1-SI \t2-NO: \n",
											"\nERROR OPCION NO VALIDA\n",1,2,3);
						if(seguir == 2){break;}
						break;
					case 4:
						printf("Modificacion cancelada\n");
						seguir=2;
						break;

					}
				}while(seguir != 2);
				}
			}}
	    else
	    {
	    printf("\nNo se ha encontrado empleado\n");
	    }
	    } //PRIMER IF NULL
return retorno;
}//ULTIMA LLAVE

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int idM;
		    int option;
		    Employee* this;
		    int i;
		    int retorno=-1;
		    int auxIdThis, auxHsThis,auxSuThis;
		    				char auxNomThis[50];
		    if(pArrayListEmployee!=NULL)
		    {
				if(utn_getNumero(&idM,"\nIngrese ID del empleado a dar de baja: \n",
									"\nERROR OPCION NO VALIDA\n",0,ll_len(pArrayListEmployee),3)==0)
				{

				for(i=0; i<idM; i++){
					this = (Employee*) ll_get(pArrayListEmployee, i);
					employee_getHorasTrabajadas(this,&auxHsThis);
				    employee_getId(this,&auxIdThis);
					employee_getNombre(this,auxNomThis);
					employee_getSueldo(this,&auxSuThis);
					if(idM == auxIdThis){
						printf("\tID\t\tNOMBRE\t\tHORAS TRABAJADAS\t\tSUELDO\n");
						printf("%10d %19s %20d %25d\n", auxIdThis,auxNomThis,auxHsThis,auxSuThis);

					utn_getNumero(&option,"\nDesea darlo de baja?:\n1- SI\n2-NO\n",
								"\nERROR OPCION NO VALIDA\n",1,2,3);
	            if(option ==2){
	                printf("Eliminacion cancelada, volviendo al menu...\n");
	                retorno= -1;
	            }else{
	                ll_remove(pArrayListEmployee, i);
	                printf("Empleado %d eliminado. \n", idM);
	                free(this);
	                retorno= 0;
	            }}}
	        }
	    }
	    printf("No se ha encontrado empleado con ID %d. \n", idM);
	    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	    int retorno = -1;
	    int i;
	    int auxIdThis=0, auxHsThis=0,auxSuThis=0;
	    char auxNomThis[50];
	    Employee* auxP=NULL;
	    if((ll_len(pArrayListEmployee))>0 &&pArrayListEmployee!=NULL){

	    	printf("\tID\t\tNOMBRE\t\tHORAS TRABAJADAS\t\tSUELDO\n");
	        for(i=0; i<ll_len(pArrayListEmployee); i++){
	            auxP = (Employee*)ll_get(pArrayListEmployee, i);


			    employee_getId(auxP,&auxIdThis);
				employee_getNombre(auxP,auxNomThis);
			    employee_getHorasTrabajadas(auxP,&auxHsThis);
				employee_getSueldo(auxP,&auxSuThis);
	            if(auxP != NULL)
	            {	retorno=0;
	            	printf("%10d %19s %20d %25d\n", auxIdThis,auxNomThis,auxHsThis,auxSuThis);
	            }
	        }
	    }else{
	    	printf("\nNO HAY NADA PARA MOSTRAR\n");
	    }
	    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int option;

    utn_getNumero(&option,"\nOrdenamiento por: \n1-ID\n 2-NOMBRE\n 3-HORAS TRABAJADAS\n 4-SALARIO\n","\n Error\n",1,4,3);

    switch(option){
    case 1:	retorno=0;
    	printf("Ordenando por id...aguarde unos instantes\n");
        ll_sort(pArrayListEmployee, employeeSortById, 0);
        printf("Ordenamiento por id realizado!\n");
        break;
    case 2:	retorno=0;
		printf("Ordenando por nombre...aguarde unos instantes\n");
        ll_sort(pArrayListEmployee, employeeSortByName, 0);
        printf("Ordenamiento por nombre realizado!\n");
        break;
    case 3:	retorno=0;
		printf("Ordenando por horas trabajadas...aguarde unos instantes\n");
        ll_sort(pArrayListEmployee, employeeSortByHours, 0);
        printf("Ordenamiento por horas trabajadas realizado!\n");
        break;
    case 4:	retorno=0;
    	printf("Ordenando por salario...aguarde unos instantes\n");
        ll_sort(pArrayListEmployee, employeeSortBySalary, 0);
        printf("Ordenamiento por salario realizado!\n");
        break;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	 int retorno = -1;
	    int auxIdThis, auxHsThis,auxSuThis;
	    char auxNomThis[50];
	    Employee* this;
	    FILE* lista = fopen(path, "w");

	    if(lista==NULL){
	        printf("Error para guardar\n");
	        return retorno;
	    }
	    fprintf(lista, "id,nombre,horasTrabajadas,sueldo\n");
	    if(pArrayListEmployee!=NULL){
	        for(int i=0; i<ll_len(pArrayListEmployee); i++){
	            this = (Employee*)ll_get(pArrayListEmployee, i);
	    		employee_getHorasTrabajadas(this,&auxHsThis);
	    	    employee_getId(this,&auxIdThis);
	    		employee_getNombre(this,auxNomThis);
	    		employee_getSueldo(this,&auxSuThis);
	            fprintf(lista, "%d,%s,%d,%d\n", auxIdThis, auxNomThis,auxHsThis, auxSuThis);
	        }
	        printf("Archivo Guardado.\n");
	        retorno = 1;
	    }
	    fclose(lista);
	    return retorno;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	    int len = ll_len(pArrayListEmployee);
	    Employee* this;
	    FILE* lista = fopen(path, "wb");

	    if(lista==NULL){
	        printf("Error para guardar\n");
	        return retorno;
	    }
	    if(pArrayListEmployee!=NULL){
	        for(int i=0; i<len; i++){
	            this = (Employee*)ll_get(pArrayListEmployee, i);
	            fwrite(this,sizeof(Employee),1,lista);
	        }
	        printf("Archivo Guardado.\n");
	        retorno = 1;
	    }
	    fclose(lista);
	    return retorno;

}
