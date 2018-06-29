#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int fd;

  fd = open("/tmp/asor/file0.txt",O_RDWR);
  dup2(fd, 1);

  cout << "Hola" << endl;
  return 0;
}
