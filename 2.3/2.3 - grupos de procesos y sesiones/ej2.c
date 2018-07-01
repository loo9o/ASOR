/*
Escribir un programa que muestre los identificadores de un proceso: identificador de
proceso, de proceso padre, de grupo de procesos y de sesión. Mostrar además el número de
archivos que puede abrir el proceso y el directorio de trabajo actual.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int  main(int argc, char *argv[]){
	pid_t pid;

	pid = getpid();
	printf("pid: %li\n",pid);
	printf("ppid: %li\n",getppid());
	printf("pgid: %li\n",getpgid(pid));
	printf("sid: %li\n",getsid(pid));	
	return 0;
}

