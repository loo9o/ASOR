/*
Ejercicio 1. ​Las funciones principales para la ejecución de programas son system() y la familia de
llamadas exec(). Escribir dos programas, uno con system() y otro con la llamada exec() adecuada,
que ejecute un programa que se pasará como argumento por línea de comandos. En cada caso,
después de la ejecución añadir una sentencia para imprimir la cadena “El comando terminó de
ejecutarse” y comprobar el resultado ¿Por qué no se imprime la cadena en los dos programas?
Nota: ​Considerar cómo deben pasarse los argumentos en cada caso para que sea sencilla la
implementación. Ejemplo: ¿Qué diferencia hay entre ejecuta ps -el​ ​y ejecuta “ps -el”​?
*/

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {

  system(argv[1]);
  //execl("/bin/ls", "ls", "-r", "-t", "-l", (char *) 0);
  cout << "Fin" << endl;
  return 0;
}
