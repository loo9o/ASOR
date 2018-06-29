#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	/* Comprobar la ocurrencia de error y notificarlo con la llamada adecuada */
	if(setuid(0) == 0){
		printf("Todo ok\n");
	}
	else{
		perror("Esto es un error");
	}
	
	return 1;
}
