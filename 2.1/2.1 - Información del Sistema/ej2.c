#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>

int main(){
	int una;
	utsname uts;
	
	una = uname(&uts);
	printf("Name: %s\n", uts.sysname);
	printf("Nodename: %s\n", uts.nodename);
	printf("Release: %s\n", uts.release);
	printf("Version: %s\n", uts.version);
	printf("Machine: %s\n", uts.machine);
	
		
	return 0;
}
