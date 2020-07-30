
#ifndef PRESTAMO_H_
#define PRESTAMO_H_
#define QTY_PRESTAMO 50
#include "cliente.h"
typedef struct
{
	int idPrestamo;
	int estado;
	int idCliente;
	int importePrestamo;
	int cantidadDeCuotasDelPrestamo;
	int isEmptyPrestamo;
}ePrestamo;
/*
 * \brief carga automaticamente array
 * \paramarray Array de prestamos a ser actualizado
 * \return retorna el Id
*/
void hardcodePrestamo (ePrestamo* array,int estado, int size,int cantidadDeCuotasDelPrestamo, int idCliente, int idPrestamo,int importePrestamo);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * \brief	Inicializa el array
 * \param array Array de prestamos a ser actualizado
 * \param size Limite del array de prestamos
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int inicializarPrestamo(ePrestamo array[], int size);
int inicializarEstado(ePrestamo array[], int size);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Busca un ID en un array y devuelve la posicion e nque se encuentra
 * \param array Array del prestamo
 * \param size Tamaño del array del prestamo
 * \param posicion int*Puntero a la posicion del array donde se encuentra el valor buscado
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int buscarPrestamo(ePrestamo array[], int size, int valorBuscado, int* posicion);
/*
 * \brief Busca primer posicion vacia
 * \param array Array de prestamo
 * \param size Tamaño del array
 * \return retorna 0 (Si encontro una posicion vacia) o -1(ERROR)
*/
int buscarEmptyPrestamo(ePrestamo array[], int size, int* posicion);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Da de alta un prestamo en una posicion del array
 * \param array Array de prestamo a ser actualiza
 * \param size Limite del array de prestamos
 * \param indice Posicion a ser actualizado
 * \param id Identificador a ser asignado al prestamo
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int altaPrestamo(ePrestamo array[], int size, int* contadorID,int indice,eCliente array2[], int size2, int idCliente);
/*
 * \brief Actualiza los datos del prestamo en una posicion del array
 * \param  array Array de prestamo a ser actualiza
 * \param size Limite del array de prestamos
 * \param idPrestamo Posicion a ser actualizado
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int bajaPrestamo(ePrestamo array[], int size, int idPrestamo,eCliente array2[], int size2);
/*
 * \brief Actualiza los datos del prestamo en una posicion del array
 * \param  array Array de prestamo a ser actualiza
 * \param size Limite del array de prestamos
 * \param idPrestamo Posicion a ser actualizado
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int modificarPrestamo(ePrestamo array[], int size, int idPrestamo,eCliente array2[], int size2);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int bajaCliente( eCliente array[], int size, int idCliente,ePrestamo array2[], int size2);

#endif /* PRESTAMO_H_ */
