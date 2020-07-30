#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
int main()
{setbuf(stdout, NULL);
		char operacion;
		float primerNumero;
		float segundoNumero;
		float resultadoSuma;
		float resultadoResta;
		float resultadoDivi;
		float resultadoMulti;
		float resultadoFacS;
		float resultadoFacP;


do{
		operacion=getChar("1-Ingresar 1er Operando\n2-Ingresar 2do Operando\n3-Calcular las operaciones\n4-Informe de resultados\n5-Salir\n");

		switch(operacion){
		case '1':
			primerNumero=getFloat("Ingrese un numero: \n");

			break;
		case '2':

			segundoNumero=getFloat("Ingrese un numero: \n");

			break;
		case '3':
		resultadoSuma=calculoSumaF(primerNumero, segundoNumero);
		resultadoResta=calculoRestaF(primerNumero, segundoNumero);
		resultadoMulti=calculoMultiplicarF(primerNumero, segundoNumero);
		resultadoDivi=calculoDivisionF(primerNumero, segundoNumero);
		resultadoFacP=factorialF(primerNumero);
		resultadoFacS=factorialF(segundoNumero);
						printf("Las operaciones estan hechas\n");
		break;
		case '4':
				printf("El primer numero cargado es: %.2f\n",primerNumero);
				printf("El segundo numero cargado es: %.2f\n",segundoNumero);

				printf("El resultado de su suma(+) es: %.2f\n", resultadoSuma);
				printf("El resultado de la resta(-) es: %.2f\n", resultadoResta);
				printf("El resultado de la multiplicacion(*) es: %.2f\n", resultadoMulti);
				printf("El resultado de la division(/) es: %.2f\n", resultadoDivi);
				printf("El factorial del primer(!) numero son: %.2f\n", resultadoFacP);
				printf("El factorial del segundo(!) numero( son: %.2f\n", resultadoFacS);
				break;
		case '5':
			printf("\n¡Hasta pronto!\n");
			break;
		default:
			printf("La operacion no es valida.\n");
			break;

		} }while(operacion!='5');
return 0;}
