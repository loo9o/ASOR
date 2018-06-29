#include <iostream>
using namespace std;
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>



/*
Escribir un programa que cumpla las siguientes especificaciones:
El programa tiene un único argumento que es la ruta a un directorio. El programa debe comprobar la corrección del argumento.
El programa recorrerá las entradas del directorio de forma que:
Si es un fichero normal, escribirá el nombre.
Si es un directorio, escribirá el nombre seguido del carácter ‘/’
Si es un enlace simbólico, escribirá el nombre seguido de ‘-><fichero al que apunta>’. Usar la función readlink(2) y dimensionar adecuadamente el buffer de la función.
Si el fichero es ejecutable, escribirá el nombre seguido del carácter ‘*’
Al final de la lista el programa escribirá el tamaño total que ocupan los ficheros (no directorios) en kilobytes.
*/

int main(int argc, char const *argv[]){
   DIR *dirp;
   struct dirent *direntp;
   struct stat estado;

   dirp = opendir(argv[1]);
     if (dirp == NULL){
       cout << "Error: No se puede abrir el directorio" << endl;
     exit(2);
   }

   /* Leemos las entradas del directorio */

   while ((direntp = readdir(dirp)) != NULL) {
     if (direntp->d_type == DT_REG){
       string original = string(argv[argc-1]) + direntp->d_name;
       int result = stat(original.c_str(),&estado);
       cout << "Fichero: " << direntp->d_name << endl;
       cout << "Long: " << estado.st_size << endl;
       cout << "__________________________" << endl;
     }
     else if(direntp->d_type == DT_DIR){
       cout << "Directorio: " << direntp->d_name << "/" <<endl;
       cout << "__________________________" << endl;
     }
     else if(direntp->d_type == DT_LNK){
       cout << "Enlace simbólico: " << direntp->d_name << "->" <<endl;
       cout << "__________________________" << endl;
     }
   }

   /* Cerramos el directorio */
   closedir(dirp);

  return 0;
}
