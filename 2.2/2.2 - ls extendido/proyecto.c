/*
Escribir un programa que cumpla las siguientes especificaciones:
● El programa tiene un único argumento que es la ruta a un directorio. El programa debe
comprobar la corrección del argumento.
● El programa recorrerá las entradas del directorio de forma que:
○ Si es un fichero normal, escribirá el nombre.
○ Si es un directorio, escribirá el nombre seguido del carácter ​ ‘/’
○ Si es un enlace simbólico, escribirá el nombre seguido de ​ ‘-><fichero al que
apunta>’​ . Usar la función ​ readlink(2) y dimensionar adecuadamente el buffer de
la función.
○ Si el fichero es ejecutable, escribirá el nombre seguido del carácter ​ ‘*’
● Al final de la lista el programa escribirá el tamaño total que ocupan los ficheros (no
directorios) en kilobytes
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>


int  main(int argc, char *argv[]){		
	struct stat sb;
	DIR *dir;
	struct dirent *dirE;
	char *dirE_Name;
	char dirE_Name2[200], buf[2048], dirE_L[200];

	if (lstat(argv[1], &sb) == -1) {
                perror("lstat");
                exit(EXIT_FAILURE);
        }
	
	if(S_ISDIR(sb.st_mode)){
		printf("---El path es un directorio---\n"); 
		dir = opendir(argv[1]);
		while ((dirE = readdir(dir)) != NULL) {
			if(dirE->d_type == DT_REG){ 
				dirE_Name = dirE->d_name;
				printf("%s\n",dirE_Name);
			}
			else if(dirE->d_type == DT_DIR){
				dirE_Name = dirE->d_name;
				strcpy(dirE_Name2,"/");
				strcat(dirE_Name2,dirE_Name);
                                printf("%s\n",dirE_Name2);
			}
			else if(dirE->d_type == DT_LNK){
				dirE_Name = dirE->d_name;
				ssize_t len = readlink(dirE_Name, buf, sizeof(buf)-1);
				//dirE_L[len]='\0';
				if (len != -1) {
  					dirE_L[len] = '\0';
				}
				else {
					perror("buf size");
				}
				strcpy(dirE_Name2,dirE_Name);
				strcat(dirE_Name2,"->");
				strcat(dirE_Name2,buf);
                                printf("%s\n",dirE_Name2);
				//printf("Apunta a %s\n",buf);

			}
		}
	}
	else{
		printf("---El path no es un directorio---\n"); 
	}

	closedir(dir);

	return 0;
}

