/*
Modificar el ejercicio 5 para que, antes de crear el fichero, se fije la máscara igual que en
el ejercicio anterior. Una vez creado el fichero, debe restaurarse la máscara original del proceso.
Comprobar el resultado con el comando ​ ls.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int  main(int argc, char *argv[]){
	int i;
	mode_t mode= 0777;

	umask(0132);
	i = open("/tmp/b.txt",O_CREAT,mode);
	if(i == -1){
		perror("Error");
	}
	return 0;
}

