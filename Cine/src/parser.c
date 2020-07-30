#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Movies.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_MoviesFromText(FILE* pFile , LinkedList* pArrayListMovies){
    Movies* pMovies;
    char varId[50], varNombre[50],varDias[50], varHorario[50], varSala[50],varEntradas[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre,varDias, varHorario, varSala,varEntradas);
    while(!feof(pFile)){
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre,varDias, varHorario, varSala,varEntradas);
        if(cant == 6){
            pMovies = movies_newParametros(varId,varNombre,varDias,varHorario,varSala,varEntradas);
            ll_add(pArrayListMovies,pMovies);
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

