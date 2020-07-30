/*
 * PrototipoTwo.h
 *
 *  Created on: Jun 22, 2020
 *      Author: cgabrielmiranda
 */

#ifndef PROTOTIPOTWO_H_
#define PROTOTIPOTWO_H_
#define SEGUNDO_LEN2 50
#define TERCER_LEN2 50
#define CUARTO_LEN2 50
#define QUINTO_LEN2 50

typedef struct
{
    int primer_parametro;
    char segundo_parametro[SEGUNDO_LEN2];
    char tercer_parametro[TERCER_LEN2];
    char cuarto_parametro[CUARTO_LEN2];
    char quinto_parametro[QUINTO_LEN2];
}PrototipoTwo;
PrototipoTwo* prototipoTwo_new(void);
PrototipoTwo* prototipoTwo_newParametros(char* primer_parametroStrToInt,char* segundo_parametroStr,char* tercer_parametroStr);
int prototipoTwo_delete(PrototipoTwo* this);

/////////INICIO INT///////////
int prototipoTwo_setPrimerParametro(PrototipoTwo* this,int primer_parametro);
int prototipoTwo_getPrimerParametro(PrototipoTwo* this,int* primer_parametro);

//////////FIN INT///////////
//////////INICIO CHAR////////////
int prototipoTwo_setSegundoParametro(PrototipoTwo* this,char* segundo_parametro);
int prototipoTwo_getSegundoParametro(PrototipoTwo* this,char* segundo_parametro);

int prototipoTwo_setTercerParametro(PrototipoTwo* this,char* tercer_parametro);
int prototipoTwo_getTercerParametro(PrototipoTwo* this,char* tercer_parametro);

int prototipoTwo_setCuartoParametro(PrototipoTwo* this,char* cuarto_parametro);
int prototipoTwo_getCuartoParametro(PrototipoTwo* this,char* cuarto_parametro);

int prototipoTwo_setQuintoParametro(PrototipoTwo* this,char* quinto_parametro);
int prototipoTwo_getQuintoParametro(PrototipoTwo* this,char* quinto_parametro);
//////////// FIN CHAR///////////

int prototipoTwoSortById(void* a, void* b);
int prototipoTwoSortByName(void* a, void* b);
int prototipoTwoSortByHours(void* a, void* b);
int prototipoTwoSortBySalary(void* a, void* b);


int prototipoTwoVentasTotales(void* p);
int prototipoTwoMayoresAx(void* p);
int PrototipoTwoMayoresAx(void* p);
int PrototipoTwoMayorCantidadNombre(void* p);
int prototipoTwo_map(void* p);


#endif /* PROTOTIPOTWO_H_ */
