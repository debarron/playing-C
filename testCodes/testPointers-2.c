#include <stdio.h>
void printElements(int *pointer, int len){
  int i = 0;

  for(i = 0; i < len; i++)
    printf("The element at %d is: %d\n", i, pointer[i]);
}

int main(){
  int matrix [3][3] ={
   {1, 2, 3},
   {4, 5, 6},
   {7, 8, 9}
  };

  printf("The size of matrix is: %lu\n", sizeof(matrix));
  printElements(&matrix[0][0], sizeof(matrix)/sizeof(int));

  return 0;
}
