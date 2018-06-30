/*
Escribir un programa que emule el comportamiento del comando ​ stat​ y muestre:
● El número ​ major y ​ minor asociado al dispositivo
● El número de inodo del archivo
● El tipo de archivo (directorio, enlace simbólico o archivo ordinario)
● La hora en la que se accedió el fichero por última vez. ¿Qué diferencia hay entre ​ st_mtime y st_ctime​

└──╼ $stat 2.1
  Fichero: 2.1
  Tamaño: 4096      	Bloques: 8          Bloque E/S: 4096   directorio
Dispositivo: 835h/2101d	Nodo-i: 10749770    Enlaces: 5
Acceso: (0755/drwxr-xr-x)  Uid: ( 1000/     loo)   Gid: ( 1000/     loo)
      Acceso: 2018-06-29 20:54:57.557988066 +0200
Modificación: 2018-06-29 20:54:55.934677062 +0200
      Cambio: 2018-06-29 20:54:55.934677062 +0200
    Creación: -
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/sysmacros.h>
/*
int stat(const char *pathname, struct stat *statbuf);
 int fstat(int fd, struct stat *statbuf);
 int lstat(const char *pathname, struct stat *statbuf);


 st_dev This field describes the device on which this file resides.  (The major(3) and minor(3) macros may be useful  to  decompose  the
                (long) major(sb.st_dev), (long) minor(sb.st_dev));

                struct stat {
                               dev_t     st_dev;         /* ID of device containing file
                               ino_t     st_ino;         /* Inode number
                               mode_t    st_mode;        /* File type and mode
                               nlink_t   st_nlink;       /* Number of hard links
                               uid_t     st_uid;         /* User ID of owner
                               gid_t     st_gid;         /* Group ID of owner
                               dev_t     st_rdev;        /* Device ID (if special file)
                               off_t     st_size;        /* Total size, in bytes
                               blksize_t st_blksize;     /* Block size for filesystem I/O
                               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated

                               // Since Linux 2.6, the kernel supports nanosecond
                              //    precision for the following timestamp fields.
                              //    For the details before Linux 2.6, see NOTES.

                               struct timespec st_atim;  // Time of last access
                               struct timespec st_mtim;  // Time of last modification
                               struct timespec st_ctim;  // Time of last status change

                           #define st_atime st_atim.tv_sec      // Backward compatibility
                           #define st_mtime st_mtim.tv_sec
                           #define st_ctime st_ctim.tv_sec
                           };

                           #include <sys/sysmacros.h>

       dev_t makedev(unsigned int maj, unsigned int min);

       unsigned int major(dev_t dev);
       unsigned int minor(dev_t dev);
time_t mktime(struct tm *timeptr);
*/

int  main(int argc, char *argv[]){
	struct stat sb;
	char arg[20] = "/dev/sda1";

	if (lstat(arg, &sb) == -1) {
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	printf("Major and minor: [%lx,%lx]\n",(long) major(sb.st_dev), (long) minor(sb.st_dev));
	printf("I-node number: %ld\n", (long) sb.st_ino);
	printf("File type: %ld\n",sb.st_mode); 
	printf("Last status change:       %s", ctime(&sb.st_ctime));
	printf("Last file access:         %s", ctime(&sb.st_atime));
	printf("Last file modification:   %s", ctime(&sb.st_mtime));

	return 0;
}

