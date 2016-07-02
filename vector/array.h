#ifndef ARRAY_H
#define ARRAY_H
#include <stdbool.h>

#define init_capacity 4

typedef int data_t;

typedef struct array {
    data_t *array;
    size_t size;
    size_t capacity;
} array;


array *vector_create();

bool vector_append(array *arr, data_t element);

void vector_print(array *arr);

void vector_free(array *arr);

data_t vector_pop(array *arr);

array *vector_create_size(size_t size);

bool vector_insert(array *arr, data_t element, int pos);

bool vector_remove(array *arr, int pos);

array *vector_copy(array *arr);

#endif

