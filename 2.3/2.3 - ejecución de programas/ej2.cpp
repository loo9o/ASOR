#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



/*
Ejercicio 2. Usando la versión exec del ejercicio anterior, y la plantilla de demonio desarrollada en la
sección anterior, escribir un programa que ejecute cualquier programa como si fuera un demonio.
Además, redirigir los flujos estándar asociados al terminal usando dup2:
● La salida estándar al fichero /tmp/daemon.out.
● La salida de error estándar al fichero /tmp/daemon.err.
● La entrada estándar a /dev/null.
Comprobar que el proceso sigue en ejecución tras cerrar la shell.
*/

//system(argv[1]);
//execl("/bin/ls", "ls", "-r", "-t", "-l", (char *) 0);

int main(int argc, char const *argv[]) {
  pid_t pid = fork();
  int fdOut, fdOutErr, fdIn;

  //fdOut = open("/tmp/daemon.out",O_CREAT,0666);
  //fdOutErr = open("/tmp/daemon.err",O_CREAT,0666);
  fdOut = open("/tmp/daemon.out",O_RDWR | O_CREAT,0666);
  fdOutErr = open("/tmp/daemon.err",O_RDWR | O_CREAT,0666);
  fdIn = open("/dev/null",O_RDWR | O_CREAT,0666);

  //cout << "PID" << pid << endl;
  //sleep(10);
  if (pid == -1) { // Error
    dup2(fdOutErr,2);
    close(fdOutErr);
    perror("Error1");
  }
  else if (pid == 0) { // Hijo
    system(argv[1]); // hay que usar exec no system

    dup2(fdOutErr,2);
    close(fdOutErr);
    dup2(fdOut,1);
    close(fdOut);
    dup2(fdIn,0);
    close(fdIn);
    cout << "PID hijo: " << pid << endl;
    perror("Error2");
  }
  else{ // Padre, pid es el PID del hijo
    /*
    system(argv[1]);
    dup2(fdOutErr,2);
    dup2(fdOut,1);
    dup2(fdIn,0);
    */
    cout << "PID padre" << pid << endl;
  }
  cout << "Fin" << endl;
  return 0;
}
