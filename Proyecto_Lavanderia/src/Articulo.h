/*
 * Movies.h
 *
 *  Created on: 18 jun. 2020
 *      Author: cgabrielmiranda
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#define SEGUNDO_LEN 50
#define TERCER_LEN 60

typedef struct
{
    int id;
    char articulo[SEGUNDO_LEN];
    char medidas[TERCER_LEN];
    int precio;
    int rubroID;
}Articulo;
Articulo* prototipo_new(void);
Articulo* prototipo_newParametros(char* primer_parametro,char* segundo_parametro,char* tercer_parametro,char* cuarto_parametro,char* quinto_parametro);
int prototipo_delete(Articulo* this);

/////////INICIO INT///////////
int prototipo_setPrimerParametro(Articulo* this,int primer_parametro);
int prototipo_getPrimerParametro(Articulo* this,int* primer_parametro);
int prototipo_setQuintoParametro(Articulo* this,int primer_parametro);
int prototipo_getQuintoParametro(Articulo* this,int* primer_parametro);
int prototipo_setCuartoParametro(Articulo* this,int cuarto_parametro);
int prototipo_getCuartoParametro(Articulo* this,int* cuarto_parametro);
//////////FIN INT///////////
//////////INICIO CHAR////////////
int prototipo_setSegundoParametro(Articulo* this,char* segundo_parametro);
int prototipo_getSegundoParametro(Articulo* this,char* segundo_parametro);
int prototipo_setTercerParametro(Articulo* this,char* tercer_parametro);
int prototipo_getTercerParametro(Articulo* this,char* tercer_parametro);
//////////// FIN CHAR///////////
int prototipoSortByName(void* a, void* b);
int ArticuloSortByName(void* a, void* b);
int prototipoMayora100(void* p);
int PrototipoMayorCantidadRubro(void* p);
int prototipo_map(void* p);
#endif /* ARTICULO_H_ */
