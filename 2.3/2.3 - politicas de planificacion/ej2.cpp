#include <iostream>
using namespace std;
#include <sched.h>


/*
Ejercicio 2. Escribir un programa que muestre la política de planificación como
una cadena y la prioridad (igual que chrt), además de mostrar los valores máximo
y mínimo de la prioridad para la política de planificación.
*/

int main(int argc, char const *argv[]) {
  int proc;
  pid_t pid = 18605;
  //int sched_setscheduler(pid_t pid, int policy,const struct sched_param *param);
  //int sched_getscheduler(pid_t pid);

  proc = sched_getscheduler(pid);

  cout << proc << endl;

  return 0;
}
