#pragma once

#define ASSERT(x) if (!(x)) printf("A test for " #x " went wrong in function %s, line %d\n", __func__, __LINE__); \
  else printf("Everything went fine in test for " #x "  in function %s, line %d\n", __func__, __LINE__);

void test_list_create();
void test_list_prepend();
void test_list_append();
void test_list_pop();
void test_list_get_el();
void test_list_reverse();