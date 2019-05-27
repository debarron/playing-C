#include <stdio.h>
void printElements(int *pointer, int len){
  int i;

  for(i = 0; i < len; i++){
    printf("The element at the position %d is: %d\n", i, pointer[i]);
  }
}

int main(){
  int array [5] = {1, 2, 3, 4, 5};
  printf("The array size is: %lu\n", sizeof(array));

  printElements(&array[0], sizeof(array)/sizeof(int));

  return 0;
}
