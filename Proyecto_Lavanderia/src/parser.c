#include <stdio.h>
#include <stdlib.h>

#include "Articulo.h"
#include "LinkedList.h"


/** \brief Parsea los datos los datos del prototipo desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPrototipo LinkedList*
 * \return int
 *
 */
int parser_PrototipoFromText(FILE* pFile , LinkedList* pArrayListPrototipo){
    Articulo* pPrototipo;
    char primer_parametro[50], segundo_parametro[50],tercer_parametro[50], cuarto_parametro[50], quinto_parametro[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro, cuarto_parametro,
    		quinto_parametro);
    while(!feof(pFile)){
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro, cuarto_parametro,
        		quinto_parametro);
        if(cant == 5){
            pPrototipo = prototipo_newParametros(primer_parametro,segundo_parametro,tercer_parametro,cuarto_parametro,quinto_parametro);
            ll_add(pArrayListPrototipo,pPrototipo);
            i++;
        }else{
            if(feof(pFile)){
                printf("\nFinal del archivo. Bytes leidos %d", i);
                system("pause");
                break;
            }
        }
    }

    printf("Datos cargados correctamente.\n");
    fclose(pFile);
    return i;
}

/** \brief Parsea los datos los datos del prototipo desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPrototipo LinkedList*
 * \return int
 *
 */
/*
int parserTwo_PrototipoFromText(FILE* pFile , LinkedList* pArrayListPrototipoTwo){
    Articulo* pPrototipo;
    char primer_parametro[50], segundo_parametro[50],tercer_parametro[50], cuarto_parametro[50], quinto_parametro[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro, cuarto_parametro,
    		quinto_parametro);
    while(!feof(pFile)){
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro, cuarto_parametro,
        		quinto_parametro);
        if(cant == 6){
            pPrototipo = prototipoTwo_newParametros(primer_parametro,segundo_parametro,tercer_parametro,cuarto_parametro,quinto_parametro);
            ll_add(pArrayListPrototipoTwo,pPrototipo);
            i++;
        }else{
            if(feof(pFile)){
                printf("\nFinal del archivo. Bytes leidos %d", i);
                system("pause");
                break;
            }
        }
    }

    printf("Datos cargados correctamente.\n");
    fclose(pFile);
    return i;
}

*/
