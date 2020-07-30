/*
 * Movies.h
 *
 *  Created on: 18 jun. 2020
 *      Author: cgabrielmiranda
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
#define FECHA_LEN 50
#define CANTIDAD_LEN 50
#define CODIGO_LEN 50
#define CUIT_LEN 50

typedef struct
{
    int id;
    char fecha[FECHA_LEN];
    char codigo[CODIGO_LEN];
    char cantidad[CANTIDAD_LEN];
    int precio;
    char cuit[CUIT_LEN];
}Productos;
Productos* producto_new(void);
Productos* producto_newParametros(char* id,char* fecha,char* codigo,char* cantidad,char* precio, char* cuit);
int producto_delete(Productos* this);
int producto_setId(Productos* this,int id);
int producto_getId(Productos* this,int* id);
int producto_automaticId();

int producto_setFecha(Productos* this,char* fecha);
int producto_getFecha(Productos* this,char* fecha);

int producto_setCodigo(Productos* this,char* codigo);
int producto_getCodigo(Productos* this,char* codigo);

int producto_setCantidad(Productos* this,char* cantidad);
int producto_getCantidad(Productos* this,char* cantidad);

int producto_setPrecio(Productos* this,int precio);
int producto_getPrecio(Productos* this,int* precio);

int producto_setCuit(Productos* this,char* cuit);
int producto_getCuit(Productos* this,char* cuit);

int productoSortById(void* a, void* b);
int productosSortByName(void* a, void* b);
int productosSortByHours(void* a, void* b);
int productosSortBySalary(void* a, void* b);


int ProductoVentasTotales(void* p);
int ProductoMayoresA10000(void* p);
int ProductoMayoresA20000(void* p);
int ProductoventasTVsLCD(void* p);
int producto_map(void* p);
#endif /* PRODUCTOS_H_ */
