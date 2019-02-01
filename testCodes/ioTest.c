#include <stdio.h>
#include <stdio.h>

int main(){
  int a, b;


  fprintf(stdout, "Put a value: ");
  fscanf(stdin, "%d", &b);
  fprintf(stdout, "\nThe value of b is: %d\n", b);
  
  return 0;
}
