/*Repetir el ejercicio anterior pero en este caso para la configuración del sistema de
ficheros, ​ pathconf(3)​ . Por ejemplo que muestre el número máximo de enlaces, el tamaño máximo
de una ruta y el de un nombre de fichero.*/

#include <sys/utsname.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
	char const *pathname = "/home";
	printf("Max links: %i\n",pathconf(pathname,_PC_LINK_MAX));
	printf("Max pathname: %i\n",pathconf(pathname,_PC_PATH_MAX));
	printf("Max length filename: %i\n",pathconf(pathname,_PC_NAME_MAX));

        return 0;
}

