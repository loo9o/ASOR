#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <time.h>
#define st_atime st_atim.tv_sec

int main() {
  int result;
  struct stat estado;
  time_t timer;
  result = stat("/tmp/asor/a.txt",&estado);
  timer = estado.st_atime;
  cout << result << endl;
  cout << "Inodo: " << estado.st_ino << endl;
  cout << "Mayor: " << major(estado.st_dev) << endl;
  cout << "Menor: " << minor(estado.st_dev) << endl;
  cout << "Tipo: " << estado.st_mode << endl;
  cout << "Último acceso: " << ctime(&timer) << endl;
  return 0;
}
