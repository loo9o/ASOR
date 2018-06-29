#include <iostream>
using namespace std;
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char const *argv[]) {

  string original = "/tmp/asor/" + string(argv[argc-1]);
  string hard = original + ".hard";
  string sym = original + ".sym";

  link(original.c_str(),hard.c_str());
  symlink(original.c_str(),sym.c_str());

  return 0;
}
