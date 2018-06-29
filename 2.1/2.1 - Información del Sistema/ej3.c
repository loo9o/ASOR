#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>

int main(){
        
	/*
	Escribir un programa que obtenga la información de configuración del sistema,
	consultar ​ sysconf(3)​ , e imprima por ejemplo, la longitud máxima de los argumentos, el número
	máximo de hijos y el número máximo de ficheros	
	*/

	printf("Max length of the arguments: %i\n",sysconf(_SC_ARG_MAX));
	printf("Max child: %i\n",sysconf(_SC_CHILD_MAX));
	printf("Max files: %i\n",sysconf(_SC_OPEN_MAX));

        return 0;
}


