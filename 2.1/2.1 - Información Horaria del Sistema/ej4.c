/*Cuando es necesario obtener la información horaria con precisión de microsegundos se
puede usar ​ gettimeofday(2)​ . Escribir un programa que mida cuánto tarda un bucle de 10.000
repeticiones en incrementar una variable en una unidad en cada iteración.*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>


int main(){
	timeval ini, fin, result;

	gettimeofday(&ini, NULL);
	for(int i = 0; i < 10000; i++){}
	gettimeofday(&fin, NULL);

	printf("Inicio: %i\n",ini.tv_usec);
	printf("Fin: %i\n",fin.tv_usec);
	result.tv_usec = fin.tv_usec - ini.tv_usec;
	printf("Resultado: %i\n",result.tv_usec);




        return 0;
}

