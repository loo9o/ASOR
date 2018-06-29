/*
Modificar el programa anterior para que, usando la función ​ strftime(3)​ , imprima
además la hora en la forma: ​ “Hoy es Lunes, 10:34
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int  main(int argc, char *argv[]){
	setlocale(LC_ALL, "es_ES");
	char outstr[200],outstrDay[200];
	time_t t;
	struct tm *tmp;

	t = time(NULL);
	tmp = localtime(&t);
	
	strftime(outstrDay, sizeof(outstrDay), "%A", tmp);
        strftime(outstr, sizeof(outstr), "%R", tmp);

	printf("Hoy es %s, %s\n",outstrDay, outstr);
	return 0;
}

