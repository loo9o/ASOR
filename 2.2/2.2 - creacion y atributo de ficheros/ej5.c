#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
Escribir un programa que, usando la llamada ​ open​ , cree un fichero con los permisos
rw-r--r-x​ . Comprobar el resultado y las características del fichero con la orden ​ ls​ .
*/

int  main(int argc, char *argv[]){
	int i;
	
	i = open("/tmp/a.txt",O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IXOTH);
	if(i == -1){
		perror("Error");
	}
	return 0;
}

