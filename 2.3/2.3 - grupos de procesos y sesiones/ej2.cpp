#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
/*
pid_t getpid(void);
pid_t getppid(void);

getpid(2), getppid(2),
getpgid(2), getsid(2)
*/
/* Ejercicio 2. Escribir un programa que muestre los identificadores de un proceso: identificador de
proceso, de proceso padre, de grupo de procesos y de sesión. Mostrar además el número de
archivos que puede abrir el proceso y el directorio de trabajo actual.*/

int main(int argc, char const *argv[]) {
  pid_t pid;

  pid = getpid();
  cout << pid << endl;
  cout << getppid() << endl;
  cout << getpgid(pid) << endl;
  cout << getsid(pid) << endl;
  return 0;
}
