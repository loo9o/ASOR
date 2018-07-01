/*
​Escribir un programa que bloquee las señales ​ SIGINT y ​ SIGTSTP​ . Después de
bloquearlas el programa debe suspender su ejecución con la llamada ​ sleep() un número de
segundos que se obtendrán de la variable de entorno ​ SLEEP_SECS​ .
Después de despertar de la llamada ​ sleep()​ , el proceso debe informar de si se recibió la señal
SIGINT y/o ​ SIGTSTP​ . En este último caso, debe desbloquearla con lo que el proceso se detendrá y
podrá ser reanudado en la shell (imprimir una cadena antes de finalizar el programa para comprobar
este comportamiento).
*/

/* NO FUNCIONA :D - ARREGLAR */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

int  main(int argc, char *argv[]){
	sigset_t set, pending;
	
	//Bloquear
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGTSTP);
	if(sigprocmask(SIG_BLOCK, &set, NULL)==1){
		perror("Error mask");
	}

	char *envS = getenv("SLEEP_SECS");
        if (envS == NULL) {
                perror("Error sleep\n");
                _exit(EXIT_FAILURE);
        }

        int s = atoi(envS);

	sleep(s);

	//sigemptyset(&pending);	
	if(sigpending(&pending) == -1){
		perror("Pending error\n");
                _exit(EXIT_FAILURE);

	}

	if(sigismember(&pending,SIGINT) == 1){
		printf("SIGINT\n");
	}
	else if(sigismember(&pending,SIGTSTP) == 1){
		printf("SIGTST unblock\n");
		sigdelset(&set,SIGTSTP);
		if (sigprocmask(SIG_UNBLOCK, &set, NULL) == -1){
			perror("Unblock error\n");
			_exit(EXIT_FAILURE);
		}

	}
	else{
		perror("Error SIG");
	}
	return 0;
}
