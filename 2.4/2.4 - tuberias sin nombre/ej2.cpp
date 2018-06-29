#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
Ejercicio 2.

Para la comunicación bi-direccional es necesario crear dos tuberías, una para
cada sentido: p_h y h_p. Escribir un programa que implemente el mecanismo de
sincronización de parada y espera:
  * El padre leerá de la entrada estándar (terminal) y enviará el mensaje al proceso
    hijo escribiendo en la tubería p_h. Entonces permanecerá bloqueado esperando la
    confirmación por parte del hijo en la otra tubería, h_p.
  * El hijo leerá de la tubería p_h, cuando haya leído y procesado el mensaje
    (escribiéndolo por la salida estándar y esperando 1 segundo) enviará el carácter
    ‘l’ al proceso padre para indicar que está listo escribiendo en la tubería h_p.
    Después de 10 mensajes enviará ‘q’ para indicar al padre que finalice.

*/

int main(int argc, char const *argv[]) {
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>

  int
  main(int argc, char *argv[])
  {
      int pipefd1[2],pipefd1[2];
      pid_t cpid;
      char buf;
/*
      if (argc != 2) {
          fprintf(stderr, "Usage: %s <string>\n", argv[0]);
          exit(EXIT_FAILURE);
      }
*/

      if (pipe(pipefd1) == -1) {
          perror("pipe1");
          exit(EXIT_FAILURE);
      }

      if (pipe(pipefd2) == -1) {
          perror("pipe2");
          exit(EXIT_FAILURE);
      }

      cpid = fork();
      if (cpid == -1) {
          perror("fork");
          exit(EXIT_FAILURE);
      }

      if (cpid == 0) {    /* Child reads from pipe */
          close(pipefd[1]);          /* Close unused write end */

          while (read(pipefd[0], &buf, 1) > 0)
              write(STDOUT_FILENO, &buf, 1);

          write(STDOUT_FILENO, "\n", 1);
          close(pipefd[0]);
          _exit(EXIT_SUCCESS);

      } else {            /* Parent writes argv[1] to pipe */
          close(pipefd[0]);          /* Close unused read end */
          write(pipefd[1], argv[1], strlen(argv[1]));
          close(pipefd[1]);          /* Reader will see EOF */
          wait(NULL);                /* Wait for child */
          exit(EXIT_SUCCESS);
      }
  }

  return 0;
}
