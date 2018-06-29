#include <iostream>
using namespace std;
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
Ejercicio 1.

Crear otra tubería con nombre (ej. tuberia2). Escribir un programa que espere
hasta que haya datos listos para leer en alguna de ellas. El programa debe
escribir la tubería desde la que se leyó y los datos leídos. Consideraciones:
 * Para optimizar las operaciones de lectura usar un buffer (ej. de 256 bytes).
 * Usar read() para leer de la tubería y gestionar adecuadamente la longitud de
 los caracteres leídos.
 * Normalmente, la apertura de la tubería para lectura se bloqueará hasta que se
 abra para escritura (ej. con echo 1 > tuberia). Para evitarlo, usar la opción
 O_NONBLOCK en open().
 * Cuando el escritor termina y cierra la tubería, select() considerará el
 descriptor siempre listo para lectura (para detectar el fin de fichero) y no se
 bloqueará. En este caso, hay que cerrar la tubería y volver a abrirla.

*/
/*
#include <sys/select.h>


#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int select(int nfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout);

void FD_CLR(int fd, fd_set *set);
int  FD_ISSET(int fd, fd_set *set);
void FD_SET(int fd, fd_set *set);
void FD_ZERO(fd_set *set);

*/

int main(int argc, char const *argv[]) {
  struct timeval timeout;
  fd_set set;
  int fdPipe1, fdPipe2, fd, rc;
  char buffer[256];

  fdPipe1 = open("/tmp/asor/tuberia", O_RDWR);
  fdPipe2 = open("/tmp/asor/tuberia2", O_RDWR);

  FD_ZERO(&set);
  FD_SET(fdPipe1, &set);
  FD_SET(fdPipe2, &set);

  timeout.tv_sec = 5;
  timeout.tv_usec = 0;

  if(fdPipe1 > fdPipe2)
    fd = fdPipe1;
  else
    fd = fdPipe2;

  rc = select(fd+1, &set, NULL, NULL, &timeout);
  if (rc == -1){
    perror("select()");
  }
  else if (rc) { //FD_ISSET(0, &set) == 1
    cout << ":D" << endl;
    if(FD_ISSET(fdPipe1, &set)){
      read(fdPipe1, &buffer, sizeof(buffer));
      cout << buffer << endl;
    }
    else{
      read(fdPipe2, &buffer, sizeof(buffer));
      cout << buffer << endl;
    }
  }
  else{
    printf("Timeout.\n");
  }

  return 0;
}
