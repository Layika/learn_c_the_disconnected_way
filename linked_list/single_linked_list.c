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
  while (first != NULL)
    {
      node* tmp = first;
      first = first->next;
      free(tmp);
    }
}

void list_append_element_end(node* list, int new_element){
  node* new_node = (node*)malloc(sizeof(node)); 
  CHECK_ALLOC(new_node); 
  new_node->data = new_element;
  new_node->next = NULL;

  if (list == NULL){
    list = new_node;
  }
  while (list->next != NULL)
    list = list->next;

  list->next = new_node;
}


int list_pop_end(node* list){
  
  node* prev_node = NULL;
  while (list->next != NULL) {
    prev_node = list;
    list = list->next; 
  } 
  
  if (prev_node)
    prev_node->next = NULL;

  int result = list->data; 
  free(list);
  return result;
}

void list_append_on_x(node* list, int new_element, int position){
  node* left;
  node* new_node = (node*)malloc(sizeof(node));
  CHECK_ALLOC(new_node);
  node *right = list;

  if (position == 0){
    new_node->data = new_element;
    new_node->next = list;
    list = new_node; 
  }
  
  else {
    for (int i = 0; i < position; ++i){
      left = right;
	right = right->next;
      } 
      new_node->data = new_element;
      left->next = new_node;
      new_node->next = right;
    }
  }

  int list_pop_on_x(node* list, int position){
    node* left;
    node* right = list;
    int popped_el;

    if (position == 0){
      popped_el = list->data;
      left = list;
      list = list->next;
      free(left);
    }
    else {
      for (int i = 0; i < position; ++i){
	left = right;
	right = right->next;
      }
      left->next = right->next;
      popped_el = right->data;
      free(right);
    }
    return popped_el;
  }
  
void test_list_create(void) {
  node* list = list_create(1);
  
  ASSERT(list->data == 1);
  
  list_free(list);
}


void test_list_append_element_end(void) {
  node* list = list_create(1);
  
  list_append_element_end(list, 2);
  
  ASSERT(list->data == 1);
  ASSERT(list->next->data == 2);
  
  list_free(list);
}

void test_list_append_many_end(void) {
  node* list = list_create(0); 
  ASSERT(list->data == 0);
  
  node* iterator = list;
  for(int i=1; i<15; ++i) {
    list_append_element_end(list, i);
	iterator = iterator->next;
	ASSERT(iterator->data == i);
      }
      list_free(list);
    }

    void test_list_pop_element_end(void) {
      node* list = list_create(1); 
      ASSERT(list_pop_end(list) == 1); 
      list = NULL;
    }


    void test_list_append_on_x(void){
      node* list = list_create(0); 
      node* iterator = list;
      for(int i=1; i<5; ++i) {
	list_append_element_end(list, i);
	iterator = iterator->next; 
      }
      list_append_on_x(list, 16, 2);
      ASSERT(list->next->data == 16);
      list_free(list);
    }

/* void test_list_pop_on_x(void){ //todo
   node* list = list_create(100); 
   node* iterator = list;
   for(int i=1; i<7; ++i) {
   list_append_element_end(list, i);
   iterator = iterator->next; 
   } 
   }
*/

int main(void) {
  
  test_list_create();
	test_list_append_element_end();
	test_list_append_many_end();
	test_list_pop_element_end(); 
	test_list_append_on_x();
	//test_list_pop_on_x();
  
	return 0;
      }
