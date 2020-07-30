

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */

int utn_getNumero(int* pResultado,char * mensaje, char * mensajeError , int minimo , int maximo , int reintentos);
int calculoCirculo(int n);
int calculoMultiplicar (int x, int y);
int calculoSuma (int x, int y);
int calculoResta (int x, int y);
int calculoDivision (int x, int y);
int utn_getCaracter(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);
int printArrayInt(int* pArray, int limite);
int ordenar(int pArray[],int size);
int calcularPromedio(float *acumulador, float *contador);
int getInt(char *mensaje);
float calculoMultiplicarF (float x, float y);
float calculoSumaF (float x, float y);
float calculoRestaF (float x, float y);
float calculoDivisionF (float x, float y);
int esNumerico(char str[]);
int soloLetras(char str[]);
int alfaNumerico(char str[]);
int esTelefono(char str[]);
char getChar(char *mensaje);
float getFloat(char *mensaje);
float factorialF(float x);
