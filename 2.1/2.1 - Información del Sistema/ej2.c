#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>

int main(){
	utsname uts;
	
	if(uname(&uts) == -1){
		printf("Error: %i - %s\n", errno, strerror(errno));
	}
	else{
		printf("==================================\n");
		printf("Information about current kernel\n");
		printf("==================================\n");
		printf("Name: %s\n", uts.sysname);
		printf("Nodename: %s\n", uts.nodename);
		printf("Release: %s\n", uts.release);
		printf("Version: %s\n", uts.version);
		printf("Machine: %s\n", uts.machine);
		printf("Domain Name: %s\n", uts.domainname);
	}
	
		
	return 0;
}
