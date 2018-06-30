/*
Las llamadas ​ link y ​ symlink crean enlaces rígidos y simbólicos respectivamente.
Escribir un programa que reciba una ruta a un fichero como argumento. Si la ruta es un fichero
regular crear un enlace simbólico y rígido (con el mismo nombre terminado en ​ .sym y ​ .hard​ ).
Comprobar el resultado con la orden ​ ls​ .
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int  main(int argc, char *argv[]){
	/*int link(const char *oldpath, const char *newpath);*/
	char symPath[30],hardPath[30];
	

	strcpy(symPath, argv[1]);
	strcat(symPath, ".sym");
	strcpy(hardPath, argv[1]);
        strcat(hardPath, ".hard");

	
	if(link(argv[1],hardPath) == -1){
		perror("Error link");
	}
	if(symlink(argv[1],symPath) == -1){
		perror("Error symlink");
	}

	return 0;
}

