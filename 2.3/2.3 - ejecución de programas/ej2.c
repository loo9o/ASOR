/*
​Usando la versión ​ exec del ejercicio anterior, y la plantilla de demonio desarrollada en la
sección anterior, escribir un programa que ejecute cualquier programa como si fuera un demonio.
Además, redirigir los flujos estándar asociados al terminal usando ​ dup2​ :
● La salida estándar al fichero ​ /tmp/daemon.out​ .
● La salida de error estándar al fichero ​ /tmp/daemon.err.
● La entrada estándar a ​ /dev/null​ .
Comprobar que el proceso sigue en ejecución tras cerrar la shell.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int  main(int argc, char *argv[]){
	pid_t pid = fork();
	int fd0,fd1,fd2;
	
	fd0 = open("/tmp/daemon.out​",O_WRONLY|O_CREAT|O_TRUNC,0666);
	fd1 = open("/tmp/daemon.err",O_WRONLY|O_CREAT|O_TRUNC,0666);
	fd2 = open("/dev/null​",O_WRONLY|O_CREAT|O_TRUNC,0666);
	
	dup2(fd0,1);
        dup2(fd1,2);
        dup2(fd2,0);
	
	if(fd0 == -1 || fd1 == -1 || fd2 == -1){
		perror("Error fd");
	
	}
	else{
		if(pid == -1){//error
			perror("fork");
		}
		else if(pid == 0){//hijo
			execvp(argv[1],argv);
			_exit(EXIT_FAILURE);
		}
		else{//padre
			int status;
    			waitpid(pid, &status, 0);//Espera al hijo
		}
	}
	return 0;
}

