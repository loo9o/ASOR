/*Modificar el programa anterior para que muestre además la hora en formato ​ legible,
usando la función ​ ctime(3)​ . ¿Dónde se reserva espacio para el valor de la cadena que devuelve la
función? ¿Es necesario liberar el puntero?*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>


int main(){
        time_t t;	
        char *tChar;
	t = time(NULL);
	
	tChar = ctime(&t);

        printf("%s\n", tChar);

        return 0;
}

