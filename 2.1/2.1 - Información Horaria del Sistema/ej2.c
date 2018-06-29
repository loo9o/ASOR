/*La función principal para obtener la hora del sistema es ​ time(2)​ . Escribir un programa
que obtenga la hora usando esta función y la muestre en el terminal.*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>


int main(){
	time_t t;
	t = time(NULL);

	printf("%i\n", t);

	return 0;
}
