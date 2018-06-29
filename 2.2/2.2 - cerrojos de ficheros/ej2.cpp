#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


/*
Ejercicio 2.

Escribir un programa que consulte y muestre en pantalla el estado del cerrojo
sobre un fichero. El proceso mostrará el estado del cerrojo (bloqueado,
desbloqueado). Además:

   - Si está desbloqueado, fijará un cerrojo de escritura y  escribirá la hora
   actual. Después suspenderá su ejecución durante 30 segundos (función sleep) y
   a continuación liberará el cerrojo.
   - Si el cerrojo está bloqueado terminará el proceso.

El programa no deberá modificar el contenido del fichero si no tiene el cerrojo.

*/

int main(int argc, char const *argv[]){
  int fd;
  time_t current_time;
  struct tm * time_info;
  char timeString[9];

  string original = "/tmp/asor/" + string(argv[argc-1]);
  fd = open(original.c_str(),O_RDWR);

  struct flock c;

  fcntl(fd, F_GETLK, &c);

  if (c.l_type == F_UNLCK){
    cout << "Desbloqueado" << endl;
    c.l_type = F_WRLCK;
    fcntl(fd, F_SETLKW, &c);
    fcntl(fd, F_GETLK, &c);
    if (c.l_type = F_WRLCK){
      cout << "Bloqueado contra escritura" << endl;
      //Hora actual
      time(&current_time);
      time_info = localtime(&current_time);
      strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
      puts(timeString);

      sleep(30);

      c.l_type = F_UNLCK;
      fcntl(fd, F_SETLKW, &c);
      fcntl(fd, F_GETLK, &c);
      if (c.l_type == F_UNLCK){
        cout << "Desbloqueado" << endl;}
      else
        cout << "Bloqueado" << endl;
    }
    else
      cout << "Desbloqueado" << endl;
  }
  else if (c.l_type = F_WRLCK)
    cout << "Bloqueado contra escritura" << endl;
  else if (c.l_type = F_RDLCK)
    cout << "Bloqueado contra lectura" << endl;
  else
    cout << "Error" << endl;

  return 0;
}
