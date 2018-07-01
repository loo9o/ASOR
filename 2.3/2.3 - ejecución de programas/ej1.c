/*
​Las funciones principales para la ejecución de programas son ​ system() y la familia de
llamadas ​ exec()​ . Escribir dos programas, uno con ​ system() y otro con la llamada ​ exec() adecuada,
que ejecute un programa que se pasará como argumento por línea de comandos. En cada caso,
después de la ejecución añadir una sentencia para imprimir la cadena ​ “El comando terminó de
ejecutarse”​ y comprobar el resultado ¿Por qué no se imprime la cadena en los dos programas?
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int  main(int argc, char *argv[]){
	//system(argv[1]);
	execvp(argv[1],argv);
	printf("El comando terminó de ejecutarse");
	return 0;
}

