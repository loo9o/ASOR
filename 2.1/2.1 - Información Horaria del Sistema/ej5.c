/*
Escribir un programa que muestre el año (p.ej. ​ “Estamos en el año 1982”​ ) usando la
función ​ localtime(2)​ .
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>


int main(){
	time_t t;
	struct tm *tStruct;
	
	t = time(NULL);
	tStruct = localtime(&t);
	
	printf("Estamos en el año %i\n",tStruct->tm_year+1900);
	return 0;
}
