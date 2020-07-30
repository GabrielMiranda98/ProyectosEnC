#include "prestamo.h"
#include "cliente.h"


#ifndef INFORMES_H_
#define INFORMES_H_
/*
 * \brief Imprimo los datos de los Clientes
 * \param array Array a recorrer de clientes
 * \param size Tamaño del array a recorrer
 * \return Retorna 0(EXITO) y -1(ERROR)
*/
int imprimirCliente(eCliente array[],int size);
/*
 * \brief Imprimo los datos de un cliente
 * \param array Array a recorrer
 * \return Retorna 0(EXITO) y -1(ERROR)
*/
int cli_imprimir(eCliente* array);
/*
 * \brief Imprimo clientes con mas prestamos activos y desactivos
 * \param array Array a recorrerer
 * \param size Tamaño del array
 * \return Retorna 0(EXITO) y -1(ERROR)
*/
int informarClientesPrestamos(eCliente array[],int size);
/*
 * \brief Imprimo los datos de los prestamos
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0(EXITO) y -1(ERROR)
*/
int pre_imprimir(ePrestamo* array);
/*
 * \brief Imprimo los datos de los prestamos
 * \param array Array a recorrer de prestamos
 * \param size Tamaño del array de prestamos a recorrer
 * \param array2 Array a recorrer de cliente
 * \param size2 Tamaño del array de clientes a recorrer
 * \return Retorna 0(EXITO) y -1(ERROR)
*/

int imprimirPrestamo(ePrestamo array[],int size,eCliente array2[], int size2);
/*
 * \brief Imprimo los datos de los prestamos que la cantidad de importe sea mayor a 1000
 * \param array Array a recorrer de prestamos
 * \param size Tamaño del array de prestamos a recorrer
 * \return Retorna 0(EXITO) y -1(ERROR)
*/
int informarPrestamos(ePrestamo array[],int size);


#endif /* INFORMES_H_ */
