#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
Escribir un programa que, usando la llamada open, cree un fichero con los
permisos rw- r-- r-x. Comprobar el resultado y las características del fichero
con la orden ls.
*/

int main(){
  int result;

  result = open("/tmp/asor/file0.txt",O_CREAT,0645);
  result = open("/tmp/asor/file1.txt",O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH|S_IXOTH);

  if(result == -1)
    cout << "Error" << endl;


  return 0;
}
