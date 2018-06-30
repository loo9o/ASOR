/*
Cuando se crea un fichero, los permisos por defecto se derivan de la máscara de usuario
(​ umask). El comando ​ umask permite consultar y fijar esta máscara. Usando este comando, fijar la
máscara de forma que los nuevos ficheros no tengan permiso de escritura para el grupo y ningún
permiso para otros. Comprobar el funcionamiento con los comandos ​ touch​ y ​ ls​ .
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int  main(int argc, char *argv[]){
	int i;
	
	i = open("/tmp/a.txt",O_TRUNC|O_CREAT,0027);
	if(i == -1){
		perror("Error");
	}
	return 0;
}

