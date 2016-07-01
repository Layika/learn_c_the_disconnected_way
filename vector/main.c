#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"

int main(){

  printf("ARR:\n");
  array* arr = vector_create();
  printf("appending vector:\n");
  vector_append(arr, 1); 
  vector_append(arr, 2);
  vector_append(arr, 3); 
  vector_append(arr, 4);
  vector_print(arr); 
  vector_append(arr, 5);
  vector_print(arr);
  
  printf("Popped: %d\n", vector_pop(arr));
  vector_print(arr);

  printf("insert 100 on pos 2:\n");
  vector_insert(arr, 100, 2);
  vector_print(arr);
  printf("insert 102 on pos 2:\n");
  vector_insert(arr, 102, 2);
  vector_print(arr);

  printf("remove from pos 3:\n");
  vector_remove(arr, 3);
  vector_print(arr);

  printf("\nARR2:\n");
  array* arr2 = vector_create_size(20);
  vector_append(arr2, 1); 
  vector_print(arr2); 

  printf("\nARR3:\n");
  array* arr3 = vector_copy(arr); 
  vector_print(arr3);

  
  vector_free(arr);
  vector_free(arr2);
  vector_free(arr3); 
  
  return 0;
}
