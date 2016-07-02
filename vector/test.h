#ifndef TEST_H
#define TEST_H

#define ASSERT(x) if (!(x)) printf("A test for " #x " went wrong in function %s, line %d", __func__, __LINE__); \
  else printf("Everything went fine in test for " #x "  in function %s, line %d\n", __func__, __LINE__);

void test_vector_create();

void test_vector_append();

void test_vector_pop();

void test_vector_create_size();

void test_vector_insert();

void test_vector_remove();

void test_vector_copy();

void test_vector_create_size_NULL_return();

void test_vector_remove_empty_array();

#endif
