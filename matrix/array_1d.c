#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* array, int size) {
  printf("|");
  for (int i = 0; i < size; i++)
    printf(" %d |", array[i]);
  printf("\n");
  
}


int main(int argc, char* argv[]) {
  
  if (argc < 2) {
    printf("Usage: %s [size of an array]\n", argv[0]);
    exit(3);
  }

  else {
    
    int x = atoi(argv[1]);
    
    int* first = (int*)malloc(sizeof(int)*x);
    
    if (first == 0) {
      printf("Error alocating memory.\n");
      exit(2);
    }
    
    for(int i = 0; i < x; ++i)
      first[i] = i + 2;


    int* random = (int*)malloc(sizeof(int)*x);
    
    if (first == 0) {
      printf("Error alocating memory.\n");
      exit(2);
    }
    
    srand(time(NULL));
    for (int i = 0; i < x; ++i) 
      random[i] = rand() % (x+1); 


    int* sum = (int*)malloc(sizeof(int)*x);
    
    if (first == 0) {
      printf("Error alocating memory.\n");
      exit(2);
    }
    
    for (int i = 0; i < x; ++i) 
      sum[i] = first[i] + random[i];
  

    print_array(first, x);
    print_array(random, x);
    print_array(sum, x);
    
    free(first);
    free(random);
    free(sum);
    
  }
  return 0;
}

