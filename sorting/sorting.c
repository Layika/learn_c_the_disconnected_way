#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITERATIONS 1000
#define ARR_SIZE 10

int partition(int* arr, int left, int right){
  int piv = arr[left];
  int i = left;
  int j = right;

  while(1){
    while(arr[i] < piv)
      i += 1;
    while(arr[j] > piv)
      j -= 1;
    if (i < j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      ++i;
      --j;
    }
    else 
      return j;
  }
}

void quicksort(int* arr, int left, int right){
  if (left < right){
    int piv_pos = partition(arr, left, right);
    quicksort(arr, left, piv_pos);
    quicksort(arr, piv_pos+1, right);
  }
}

void print_array(int *array, int size){
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n\n");
}

void bubblesort(int *array, int size){
  
  for (int i = 0; i < (size-1); ++i){
    int swap = 0;
    for (int j = 0; j < (size-1-i); ++j){
      if (array[j] > array[j+1]){
	int temp = array[j];
	array[j] = array[j+1];
	array[j+1] = temp;
	++swap;
      }
    }
    if (!swap) break; 
  } 
}

int main(){
  int* arr_random = malloc(ARR_SIZE*sizeof(int));
  int* arr_sort = malloc(ARR_SIZE*sizeof(int));
  
  srand(time(0));
  for (int i = 0; i < ARR_SIZE; ++i) 
    arr_random[i] = rand();
  
  clock_t time_quick = 0;
  clock_t time_bubble = 0;
  
  for (int i = 1; i <= ITERATIONS; ++i){
    for (int j = 0; j < ARR_SIZE; ++j)
      arr_sort[j] = arr_random[j];
    
    clock_t t0 = clock();
    quicksort(arr_sort, 0, ARR_SIZE-1);
    clock_t t1 = clock();
    time_quick += t1 - t0; 
  }
  printf("time for quicksort: %ld\n\n", time_quick);

  for (int i = 1; i <= ITERATIONS; ++i){
    for (int j = 0; j < ARR_SIZE; ++j)
      arr_sort[j] = arr_random[j];
    
    clock_t t0 = clock(); 
    bubblesort(arr_sort, ARR_SIZE);
    clock_t t1 = clock();
    time_bubble += t1 - t0; 
  }
  printf("time for bubblesort: %ld\n\n", time_bubble);

  free(arr_random);
  free(arr_sort);
}
  
