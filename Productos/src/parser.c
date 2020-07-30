#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Productos.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ProductosFromText(FILE* pFile , LinkedList* pArrayListProductos){
    Productos* pProducto;
    char varId[50], varFecha[50],varCodigo[50], varCantidad[50], varPrecio[50],varCUIT[50];
    int cant, i = 0;
    cant = fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", varId, varFecha,varCodigo, varCantidad, varPrecio,varCUIT);
    while(!feof(pFile)){
    	cant = fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", varId, varFecha,varCodigo, varCantidad, varPrecio,varCUIT);
        if(cant == 6){
            pProducto = producto_newParametros(varId,varFecha,varCodigo,varCantidad,varPrecio,varCUIT);
            ll_add(pArrayListProductos,pProducto);
            i++;
        }
        else{
            if(feof(pFile)){
                printf("\nFinal del archivo. Bytes leidos %d", i);
                system("pause");
                break;
            }
        }
    }

    fclose(pFile);
    return i;
}

