#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"

array* vector_create(){
  array* arr = vector_create_size(init_capacity);
  
  arr->capacity = init_capacity;
  arr->size = 0;
  
  return arr;
}

bool vector_append(array* arr, data_t element){

  if (!arr)
    return false;
  
  else if (arr->size == arr->capacity){
    arr->capacity *= 2;
    data_t* bigger_array = realloc(arr->array, arr->capacity * sizeof(data_t));
    
    if(bigger_array != NULL) 
      arr->array = bigger_array; 
    else 
      return false; 
  }
  
  arr->array[arr->size] = element; 
  arr->size += 1; 
  return true;
}


void vector_print(array* arr){

  if (!arr)
    printf("The array is empty!\n");
  else {
    printf("[%d", arr->array[0]);
    for (size_t i = 1; i < arr->size; ++i)
      printf(", %d", arr->array[i]); 
    printf("] (size: %lu, capacity: %lu)\n", arr->size, arr->capacity);
  }
}


void vector_free(array* arr){
  free(arr->array); 
  free(arr); 
}


data_t vector_pop(array* arr){

  int index = arr->size - 1;
  data_t ret_el = arr->array[index];
  arr->array[index] = 0;
  --arr->size; 
  return ret_el;
}

array* vector_create_size(size_t size){
  array* arr = (array*)malloc(sizeof(array));
  if (arr == NULL)
    return NULL;
  
  arr->array = (data_t*)malloc(sizeof(data_t) * size);
  if (arr->array == NULL){
    free(arr);
    return NULL;
  }
  
  arr->capacity = size;
  arr->size = 0;
  
  return arr; 
}


bool vector_insert(array* arr, data_t element, int position){
  if (!arr)
    return false;
  
  else if (arr->size == (arr->capacity-1)){
    arr->capacity *= 2;
    data_t* bigger_array = realloc(arr->array, arr->capacity * sizeof(data_t));
    
    if(bigger_array != NULL) 
      arr->array = bigger_array; 
      else 
	return false; 
    }
   
    memmove((arr->array+position+1), (arr->array+position), (arr->size - position)*sizeof(data_t)); 
    arr->array[position] = element;
    arr->size += 1;
    return true;
  }


  bool vector_remove(array* arr, int position){
    if (!arr)
      return false;
 
    memmove((arr->array+position), (arr->array+position+1), (arr->size-position-1)*sizeof(data_t));
    arr->size =  arr->size - 1;
    return true;
  }


  array* vector_copy(array* arr){
    
    array* arr3 = vector_create_size(arr->capacity);
  
    arr3->capacity = arr->capacity;
    arr3->size = arr->size;
    memcpy(arr3->array, arr->array, (arr->size)*sizeof(data_t));
  
    return arr3;
  }
