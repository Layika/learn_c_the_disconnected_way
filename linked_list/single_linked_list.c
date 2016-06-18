#include <stdio.h>
#include <stdlib.h>
#define ASSERT(x) printf("Assertion: " #x " = %d\n", (x))

typedef int data_t;

typedef struct node {
  data_t data;
  struct node *next;
} node;

#define CHECK_ALLOC(ptr)						\
  if (!ptr) {								\
    printf("Error allocating memory for %s in  %s: %d line", #ptr, __func__, __LINE__-1); \
    exit(2);								\
  }

node* list_create(data_t data){
  node* first = (node*)malloc(sizeof(node));
  CHECK_ALLOC(first);
  first->data = data;
  first->next = NULL;
  return first;
}


void list_free(node* first){
  struct node* tmp;

  while (first != NULL)
    {
      tmp = first;
      first = first->next;
      free(tmp);
    }
}

void list_append_element(node* list, int new_element){
  node* new_node = (node*)malloc(sizeof(node)); 
  CHECK_ALLOC(new_node); 
  new_node->data = new_element;
  new_node->next = NULL;

  if (list->next == NULL)
    list->next = new_node;
  else {
    node* current_node = list;
    while (current_node->next != NULL) {
      current_node = current_node->next; 
    }
    current_node->next = new_node; 
  }
}

int list_pop(node* list){
  node* temp = list;
  node* new_tail;

  while (temp->next != NULL) {
    new_tail = temp;
    temp = temp->next; 
  }
  return temp->data;
}

void test_list_create(void) {
  node* list = list_create(1);
  
  ASSERT(list->data == 1);
  
  list_free(list);
}


void test_list_append_element(void) {
  node* list = list_create(1);
  
  list_append_element(list, 2);
  
  ASSERT(list->data == 1);
  ASSERT(list->next->data == 2);
  
  list_free(list);
}

void test_list_append_many(void) {
  node* list = list_create(0);
  
  ASSERT(list->data == 0);
  
  node* iterator = list;
  for(int i=1; i<15; ++i) {
    list_append_element(list, i);
    iterator = iterator->next;
    ASSERT(iterator->data == i);
  }
  list_free(list);
}

void test_list_pop(void) {
  node* list = list_create(1); 
  ASSERT(list_pop(list) == 1); 
  list_free(list); 
  list = NULL;
}

int main(void) {
  
  test_list_create();
  test_list_append_element(); 
  test_list_append_many();
  
  return 0;
}
