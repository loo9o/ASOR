/*
Escribir un programa que consulte y muestre en pantalla el estado del cerrojo sobre un
fichero. El proceso mostrará el estado del cerrojo (bloqueado, desbloqueado). Además:
● Si está desbloqueado, fijará un cerrojo de escritura y escribirá la hora actual. Después
suspenderá su ejecución durante 30 segundos (función ​ sleep​ ) y a continuación liberará el
cerrojo.
● Si el cerrojo está bloqueado terminará el proceso.
El programa no deberá modificar el contenido del fichero si no tiene el cerrojo.	
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int  main(int argc, char *argv[]){
	struct flock c;
	int fd;
	time_t t;
        struct tm *tmp;
	char timeString[9];

        t = time(NULL);
        tmp = localtime(&t);
	
	fd = open(argv[1],O_RDWR);
	
	if(fd == -1){
		perror("Error fd");
	}
	else{
		c.l_type = F_WRLCK;
		c.l_whence = SEEK_SET;
		c.l_start = 0;
		c.l_len = 200;

		if(fcntl(fd, F_GETLK, &c) ==  -1){
			perror("Error fcntl\n");
		}

		if(c.l_type == F_UNLCK){ //Desbloqueado 
			printf("Cerrojo Desbloqueado\n");
			c.l_type = F_WRLCK; //Cerrojo contra escritura
			fcntl(fd, F_SETLK, &c);
			printf("Cerrojo Bloqueado contra escritura\n");
			strftime(timeString, sizeof(timeString),"%H:%M:%S", tmp);
			sleep(30);
			c.l_type = F_UNLCK; 
			fcntl(fd, F_SETLK, &c);//Desbloqueado
		}
		else if(c.l_type == F_WRLCK){
    			printf( "Bloqueado contra escritura\n");
  		}
		else if (c.l_type == F_RDLCK){
    			printf("Bloqueado contra lectura\n");
		}
		else{
    			perror( "Error\n");
		}
	}

	return 0;
}




