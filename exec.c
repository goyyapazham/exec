#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

  char file[100];
  printf("Type stuff: ");
  fgets(file, 100, stdin);
  file[strcspn(file, "\n")] = 0; //remove trailing newline
  
  
  char * s;
  s = file;
  char * command[32];

  int i = 0;
  while ( s ) {
    command[i] = strsep ( &s, " " );
    i++;
  }

  execvp(command[0], command);

  return 0;
}
