/*
 * Movies.h
 *
 *  Created on: 18 jun. 2020
 *      Author: cgabrielmiranda
 */

#ifndef PROTOTIPO_H_
#define PROTOTIPO_H_
#define SEGUNDO_LEN 50000
#define TERCER_LEN 50
#define CUARTO_LEN 50000
#define QUINTO_LEN 50

typedef struct
{
    int id_mensaje;
    char idUsuario[SEGUNDO_LEN];
    char Followers[TERCER_LEN];
    char mensaje[CUARTO_LEN];
}Mensaje;
Mensaje* prototipo_new(void);
Mensaje* prototipo_newParametros(char* primer_parametroStrToInt,char* segundo_parametroStr,char* tercer_parametroStr,char* cuarto_parametroStr);
int prototipo_delete(Mensaje* this);

/////////INICIO INT///////////
int prototipo_setPrimerParametro(Mensaje* this,int primer_parametro);
int prototipo_getPrimerParametro(Mensaje* this,int* primer_parametro);
//////////FIN INT///////////
//////////INICIO CHAR////////////
int prototipo_setSegundoParametro(Mensaje* this,char* segundo_parametro);
int prototipo_getSegundoParametro(Mensaje* this,char* segundo_parametro);

int prototipo_setTercerParametro(Mensaje* this,char* tercer_parametro);
int prototipo_getTercerParametro(Mensaje* this,char* tercer_parametro);

int prototipo_setCuartoParametro(Mensaje* this,char* cuarto_parametro);
int prototipo_getCuartoParametro(Mensaje* this,char* cuarto_parametro);

//////////// FIN CHAR///////////

int prototipoSortById(void* a, void* b);
int prototipoSortByName(void* a, void* b);
int prototipoSortByHours(void* a, void* b);
int prototipoSortBySalary(void* a, void* b);


int prototipoVentasTotales(void* p);
int prototipoMayoresAx(void* p);
int prototipoMayoresAx(void* p);
int PrototipoMayorCantidadNombre(void* p);
int prototipo_map(void* p);

#endif /* PROTOTIPO_H_ */
