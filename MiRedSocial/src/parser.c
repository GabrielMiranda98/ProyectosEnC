#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Prototipo.h"
#include "PrototipoTwo.h"


/** \brief Parsea los datos los datos del prototipo desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPrototipo LinkedList*
 * \return int
 *
 */
int parser_PrototipoFromText(FILE* pFile , LinkedList* pArrayListPrototipo){
    Mensaje* pPrototipo;
    char primer_parametro[SEGUNDO_LEN], segundo_parametro[SEGUNDO_LEN],tercer_parametro[SEGUNDO_LEN], cuarto_parametro[SEGUNDO_LEN];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro, cuarto_parametro);
    while(!feof(pFile)){
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro, cuarto_parametro);
        if(cant == 4){
            pPrototipo = prototipo_newParametros(primer_parametro,segundo_parametro,tercer_parametro,cuarto_parametro);
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
int parserTwo_PrototipoFromText(FILE* pFile , LinkedList* pArrayListPrototipoTwo){
    PrototipoTwo* pPrototipo;
    char primer_parametro[50], segundo_parametro[50],tercer_parametro[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro);
    while(!feof(pFile)){
        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", primer_parametro, segundo_parametro,tercer_parametro);
        if(cant == 3){
            pPrototipo = prototipoTwo_newParametros(primer_parametro,segundo_parametro,tercer_parametro);
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

