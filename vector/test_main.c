#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"
#include "test.h"


int main(){
  test_vector_create();
  test_vector_append();
  test_vector_pop();
  test_vector_create_size();
  test_vector_insert();
  test_vector_remove();
  test_vector_copy();
  return 0;
}
