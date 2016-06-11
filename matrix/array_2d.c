#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int** array, int x, int y) {
  
  for (int i = 0; i < x; ++i){
    for (int j = 0; j < y; ++j){
      printf(" %3d |", array[i][j]);
    }
    printf("\n"); 
    for (int j = 0; j < y; ++j)
      printf("-----|");
    printf("\n");
  }
  printf("\n\n");
}

#define CHECK_ALLOC(ptr)						\
  if (!ptr) {								\
    printf("Error allocating memory for %s in  %s:%d line", #ptr, __func__, __LINE__-2); \
    exit(2);								\
    }

int** allocate_2d_array(size_t x, size_t y) {
  int** array = (int**) malloc(sizeof(int*) * y);
  // array[y-1]
  CHECK_ALLOC(array);
  for(size_t i=0; i<y; ++i) {
    array[i] = (int*) malloc(sizeof(int) * x);
    CHECK_ALLOC(array[i]);
  }
  return array;
}

int main(int argc, char* argv[]) {
  
  if (argc < 3) {
    printf("Usage: %s <array_width> <array_height>\n", argv[0]);
    exit(2);
  }

  else{
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    int** input_array = allocate_2d_array(x, y);
    
    for (int j = 0; j < y; ++j) 
      for (int i = 0; i < x; ++i)
	input_array[i][j] = i+2*j;
    


    int** random_array = allocate_2d_array(x, y);
    
    srand(time(NULL));
    
    for (int j = 0; j < y; ++j){
      for (int i = 0; i < x; ++i){
	*( *(random_array+i) + j) = rand() % x+1;
      }
    }


    int** sum_array = allocate_2d_array(x, y);
    
    for (int j = 0; j < y; ++j){
      for (int i = 0; i < x; ++i){
	sum_array[i][j] = input_array[i][j] + random_array[i][j];
      }
    }
    
    print_array(input_array, x, y);
    print_array(random_array, x, y);
    print_array(sum_array, x, y);
    
    for (int i = 0; i < x; ++i){
      free(input_array[i]);
      free(random_array[i]);
      free(sum_array[i]);
    } 

    free(input_array);
    free(random_array);
    free(sum_array);

  }
  return 0;
}
