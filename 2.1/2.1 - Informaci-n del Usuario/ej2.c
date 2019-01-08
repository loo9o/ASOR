#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>

/*
Ejercicio 2. Escribir un programa que muestre, igual que el comando ​ id​ , el UID real y efectivo del
usuario. ¿En qué circunstancias podríamos asegurar que el fichero tiene activado el bit ​ setuid ?
*/

/*
Podríamos asegurarlo en el momento que sea ejecutado por otro usuario que no sea su dueño, ya que UID y EUID no serían el mismo. El usuario real (UID) es el que ejecuta el proceso y el usuario efectivo (EUID) es en el que se ejecuta el proceso. Si el bit está activo indica que el usuario efectivo es el dueño.
*/

int main() {

	printf("UID: %i\n", getuid());
	printf("EUID: %i\n", geteuid());
	if (geteuid() != getuid())
		printf("Activado el bit setuid\n");
			
	return 1;
}
