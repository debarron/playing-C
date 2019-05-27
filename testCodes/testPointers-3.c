#include <stdio.h>
void printElements(char *pointer, int len){
  int i;

  for(i = 0; i < len; i++)
    printf("The value at %d has the value of: %d\n", i, pointer[i]);
}
int main(){
  int number = 1;
  char *pointer = (char *)&number;
  printf("The value is: %d\n", number);

  pointer[0] = 0;
  pointer[1] = 1;
  printf("The value is: %d\n", number);

  printElements((char *)&number, sizeof(int));
  return 0;
}
