#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>
#include <pwd.h>

/*
Ejercicio 3. Modificar el programa anterior para que se muestre además el nombre de usuario, el
directorio home e información del usuario.
*/

int main() {
	struct passwd *pwd;
	
	pwd = getpwuid(getuid());
	
	printf("UID: %i\n", getuid());
	printf("EUID: %i\n", geteuid());
	printf("Username: %s\n", pwd->pw_name);
	printf("Home directory: %s\n", pwd->pw_dir);
	printf("User info: %s\n", pwd->pw_gecos);

	if (geteuid() != getuid())
		printf("Activado el bit setuid\n");
			
	return 1;
}
