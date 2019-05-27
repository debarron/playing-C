#include <stdio.h>
void foo(int *a){
  *a = 30;
}

int main(){
  int a = 2;
  foo(&a);
  printf("The variable is equal to: %d\n", a);

  return 0;
}
