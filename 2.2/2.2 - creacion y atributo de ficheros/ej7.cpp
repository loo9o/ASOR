#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
Modificar el ejercicio 5 para que, antes de crear el fichero, se fije la máscara
igual que en el ejercicio anterior. Una vez creado el fichero, debe restaurarse
la máscara original del proceso. Comprobar el resultado con el comando ls.
*/

int main(){
  int result;
  mode_t mode = 0777;
  umask(0132);

  result = open("/tmp/asor/file2.txt",O_CREAT,mode);

  if(result == -1)
    cout << "Error" << endl;

  return 0;
}
