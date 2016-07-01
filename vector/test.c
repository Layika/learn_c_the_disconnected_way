#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array.c"
#include "test.h"

void test_vector_create(){
  array* arr =  vector_create(); 
  ASSERT(arr->capacity == init_capacity);
  ASSERT(arr->size == 0);

  vector_free(arr);
}

void test_vector_append(){
  array* arr =  vector_create();
  vector_append(arr, 5); 
  ASSERT(arr->array[0] == 5);
  ASSERT(arr->size == 1);
  
  vector_free(arr);
}

void test_vector_pop(){
  array* arr =  vector_create();
  vector_append(arr, 5);
  vector_append(arr, 4);
  vector_append(arr, 3);
  data_t popped_el = vector_pop(arr);
  ASSERT(popped_el == 3);

  vector_free(arr);
}

void test_vector_create_size(){
  array* arr =  vector_create_size(36);
  ASSERT(arr->capacity == 36);
  ASSERT(arr->size == 0);
  free(arr);
}

void test_vector_insert(){
  array* arr =  vector_create();
  vector_append(arr, 5);
  vector_append(arr, 4);
  vector_append(arr, 3); 
  vector_insert(arr, 100, 2);
  ASSERT(arr->array[2] == 100);

  vector_free(arr);
}

void test_vector_remove(){
  array* arr =  vector_create();
  vector_append(arr, 5);
  vector_append(arr, 4);
  vector_append(arr, 3);
  vector_insert(arr, 100, 2);
  vector_remove(arr, 2);
  ASSERT(arr->array[2] == 3);

  vector_free(arr);
}

void test_vector_copy(){
  array* arr =  vector_create();
  vector_append(arr, 0);
  vector_append(arr, 3);
  vector_append(arr, 5);
  array* copy_arr = vector_copy(arr);
  ASSERT(copy_arr->array[0] == 0);
  ASSERT(copy_arr->array[1] == 3);
  ASSERT(copy_arr->array[2] == 5);
  ASSERT(copy_arr->size == 3);
  ASSERT(copy_arr->capacity == 4);

  vector_free(arr);
  vector_free(copy_arr);
}

void test_vector_create_size_NULL_return(){
  size_t max_size = (size_t)-1;
  array* arr = vector_create_size(max_size);
  ASSERT(arr == NULL);
}
