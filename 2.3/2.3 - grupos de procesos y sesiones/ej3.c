/*
Normalmente un demonio está en su propia sesión y grupo. Para garantizar que es
posible crear la sesión y grupo el proceso hace un ​ fork() en el que ejecuta la lógica del demonio y
crea la nueva sesión. Escribir una plantilla de demonio (​ fork y la creación de una nueva sesión) en el
que únicamente se muestren los atributos de los procesos (como en el ejercicio anterior). Además
un demonio tiene un directorio de trabajo definido, fijar el de nuestra plantilla al ​ /tmp​ .
¿Qué sucede si el proceso padre termina antes de que el hijo imprima su información (observar el
PID del proceso padre)? ¿Y si el proceso que termina antes es el hijo (observar con ​ ps ​ el estado del
proceso hijo)
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int  main(int argc, char *argv[]){
	pid_t pid = fork();
	char path[2048];
	char cwd[2048];

	
	strcpy(path,"/tmp");
	chdir(path);
	if (getcwd(cwd, sizeof(cwd)) != NULL){
		printf("Dir: %s\n", cwd);
	}	
	
	if(pid == -1){
		perror("Error fork");
	}
	else if(pid == 0){ //hijo
		pid = getpid();
		printf("--HIJO--");
        	printf("pid: %li\n",pid);
        	printf("ppid: %li\n",getppid());
       		printf("pgid: %li\n",getpgid(pid));
        	printf("sid: %li\n",getsid(pid));
	}
	else{ //padre
		printf("--PADRE--");
                printf("pid: %li\n",pid);
                printf("ppid: %li\n",getppid());
                printf("pgid: %li\n",getpgid(pid));
                printf("sid: %li\n",getsid(pid));
	}
	
	return 0;
}

