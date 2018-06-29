#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
	int error;
        if(setuid(0) == 0){
                printf("Bien\n");
        }
        else{
        	printf("Error: %i %s\n ", errno, strerror(errno));
		
	}

        return 1;
}

