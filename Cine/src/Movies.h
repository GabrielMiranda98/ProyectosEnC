/*
 * Movies.h
 *
 *  Created on: 18 jun. 2020
 *      Author: cgabrielmiranda
 */

#ifndef MOVIES_H_
#define MOVIES_H_
#define NOMBRE_LEN 50
#define HORARIO_LEN 50
#define DIAS_LEN 50
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    char dias[DIAS_LEN];
    int dia;
    char horario[HORARIO_LEN];
    int sala;
    int cantidadEntradas;
    int montoFacturado;
}Movies;


Movies* movies_new(void);

Movies* movies_newParametros(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr,char* cantidadEntradas);
Movies* movies_newParametros1(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr,char* cantidadEntradasStr,char* montoFacturadoStr);

int movies_delete(Movies* this);

int movies_setId(Movies* this,int id);
int movies_getId(Movies* this,int* id);

int movies_automaticId();


int movies_setNombre(Movies* this,char* nombre);
int movies_getNombre(Movies* this,char* nombre);

int movies_setDiaInt(Movies* this,int dia);
int movies_getDiaInt(Movies* this,int* dia);

int movies_setDiaChar(Movies* this,char* dia);
int movies_getDiaChar(Movies* this,char* dia);

int movies_setHorario(Movies* this,char* horario);
int movies_getHorario(Movies* this,char* horario);

int movies_setsala(Movies* this,int sala);
int movies_getsala(Movies* this,int* sala);

int movies_setcantidadEntradas(Movies* this,int cantidadEntradas);
int movies_getcantidadEntradas(Movies* this,int* cantidadEntradas);

int movies_setmontoFacturado(Movies* this,int montoFacturado);
int movies_getmontoFacturado(Movies* this,int* montoFacturado);

int moviesSortById(void* empleadoA, void* empleadoB);
int moviesSortByName(void* empleadoA, void* empleadoB);
int moviesSortByHours(void* empleadoA, void* empleadoB);
int moviesSortBySalary(void* empleadoA, void* empleadoB);

int movieMapMontofacturado(void* p);
int movieFilterSala1(void* p);
int movieFilterSala2(void* p);
int movieFilterSala3(void* p);
int movieFilterSala4(void* p);
int movieFilterSala5(void* p);

#endif /* MOVIES_H_ */
