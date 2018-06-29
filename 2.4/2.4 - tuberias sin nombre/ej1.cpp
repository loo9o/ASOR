#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*

Ejercicio 1.
Comunicación por tuberías.

Escribir un programa que emule el comportamiento de la shell en la ejecución de
una sentencia en la forma: comando1 argumento1 | comando2 argumento2. El
programa abrirá una tubería sin nombre y creará un hijo:
  * El programa padre ejecutará comando1 argumento1 y redireccionará la salida
    estándar al extremo de escritura de la tubería.
  * El hijo, ejecutará comando2 argumento2, en este caso la entrada estándar deberá
    duplicarse con el extremo de lectura de la tubería.
  * Probar el funcionamiento con una sentencia similar a: ./ejercicio1 echo 12345 wc -c

Nota: antes de ejecutar el comando correspondiente deben cerrarse todos los
descriptores no necesarios.

*/



int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buf;
/*
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
*/
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* Child reads from pipe */
        close(pipefd[1]);          /* Close unused write end */

        //while (read(pipefd[0], &buf, 1) > 0)
          //write(STDOUT_FILENO, &buf, 1);
          //write(STDOUT_FILENO, "\n", 1);
        dup2(pipefd[0],0);
        close(pipefd[0]);
        execlp(argv[3],argv[3],argv[4],NULL);

    } else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        //write(pipefd[1], argv[1], strlen(argv[1]));
        dup2(pipefd[1],1);
        close(pipefd[1]);          /* Reader will see EOF */
        execlp(argv[1], argv[1], argv[2], NULL);
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}
