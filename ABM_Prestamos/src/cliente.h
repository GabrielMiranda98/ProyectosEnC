
#ifndef CLIENTE_H_
#define CLIENTE_H_
#define QTY_CLIENTE 50

typedef struct
{
	int idCliente;
	int cantidadDePrestamos;
	int acumuladorDeMonto;
	int cuotasAcumuladas;
	int estadoPrestamos;
	char cuilCliente[51];
	char nombreCliente[51];
	char apellidoCliente[51];
	int isEmptyCliente;
	int cPrestamoActivo;
	int cPrestamoSaldado;

}eCliente;

void hardcodeCliente (eCliente array[], int size, int id, char nombre[], char apellido[], char cuil[], int cantidadDeprestamos, int cuotas, int activo,int saldado);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int inicializarCliente(eCliente array[], int size);
int inicializarCantidadDePrestamos(eCliente array[], int size);
int inicializarMonto(eCliente array[], int size);
int inicializarCuotas(eCliente array[], int size);

int inicializarcPrestamoSaldado(eCliente array[], int size);
int inicializarcPrestamoActivo(eCliente array[], int size);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array Array del prestamo
 * \param size Tamaño del array del prestamo
 * \param posicion int*Puntero a la posicion del array donde se encuentra el valor buscado
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int buscarCliente(eCliente array[], int size, int valorBuscado, int* posicion);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de cliente a ser actualiza
 * \param size Limite del array de cliente
 * \param indice Posicion a ser actualizado
 * \param id Identificador a ser asignado al cliente
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int altaCliente(eCliente array[], int size, int* contadorID);
// BAJA DE CLIENTE EN BIBLIOTECA PRESTAMO.
/*
 * \brief Actualiza los datos del cliente en una posicion del array
 * \param  array Array de cliente a ser actualiza
 * \param size Limite del array de cliente
 * \param indice Posicion a ser actualizado
 * \return retorna 0 (EXITO) o -1(ERROR)
*/
int modificarCliente(eCliente array[],int limite, int indice);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif /* CLIENTE_H_ */
