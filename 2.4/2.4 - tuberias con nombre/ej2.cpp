#include <iostream>
using namespace std;
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
Ejercicio 2. Escribir un programa que abra la tubería con el nombre anterior
($HOME/tuberia) en modo sólo escritura, y escriba en ella el primer argumento
del programa. En otro terminal, leer de la tubería usando un comando adecuado.
*/

int main(int argc, char const *argv[]) {
  //struct rlimit limit;
  int fd = open("/tmp/asor/pipe", O_CREAT|O_WRONLY, 0666);
/*
  getrlimit (RLIMIT_FSIZE, &limit);
  size_t size = limit.rlim_cur;
  cout << "limite: " << limit.rlim_cur << endl;
*/

  //write(fd,argv[1],size);

  string arg = string(argv[1])+"\n";
  write(fd,arg.c_str(),arg.length());
  
  close(fd);

  return 0;
}
