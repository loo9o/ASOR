#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
Modificar el programa anterior para que además de escribir en el fichero la
salida estándar también se escriba la salida estándar de error. Comprobar el
funcionamiento incluyendo varias sentencias que impriman en ambos flujos. ¿Hay
alguna diferencia si las redirecciones se hacen en diferente orden? ¿Por qué no
es lo mismo “ls > dirlist 2>&1” que “ls 2>&1 > dirlist”?
*/


int main(int argc, char const *argv[]){
  int fd;

  string original = "/tmp/asor/" + string(argv[argc-1]);
  fd = open(original.c_str(),O_RDWR);

  dup2(fd, 1);
  close(fd);
  // 2>&1
  dup2(1, 2);
  perror("Error");
  cout << "Hola" << endl;

  return 0;
}
