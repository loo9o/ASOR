/*
Escribir un programa que redirija la salida estándar a un fichero, cuya ruta se pasa como
primer argumento. Probar escribiendo varias cadenas en la salida estándar.	
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int  main(int argc, char *argv[]){
	int fd;

	fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
	
	if(fd == -1){
		perror("Error fd");
	}
	else{
		dup2(fd,1);
		printf("Freedom 0: The freedom to run the program for any purpose\n");
                printf("Freedom 1: The freedom to study how the program works, and change it to make it do what you wish.\n");
                printf("Freedom 2: The freedom to redistribute copies so you can help your neighbor.\n");
                printf("Freedom 3: The freedom to improve the program, and release your improvements (and modified versions in general) to the public, so that the whole community benefits.\n");
		printf("¡LIBRELABUCM!\n");
	}
	return 0;
}

