#include "test.h"

int main() {
    test_vector_create();
    test_vector_append();
    test_vector_pop();
    test_vector_create_size();
    test_vector_insert();
    test_vector_remove();
    test_vector_copy();
    test_vector_create_size_NULL_return();
    test_vector_remove_empty_array();
    return 0;
}
