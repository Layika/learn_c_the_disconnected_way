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

void list_append(node** list, int new_element){
  node* new_node = (node*)malloc(sizeof(node)); 
  CHECK_ALLOC(new_node); 
  new_node->data = new_element;
  new_node->next = NULL;

  if (*list == NULL){
    *list = new_node;
  }
  else {
    node* current = *list;
    while (current->next)
      current = current->next;
    current->next = new_node;
  }
}


int list_pop(node* list){

  if (!list)
    return -1;
  
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

void list_insert(node** list, int new_element, int position){
  node* left;
  node* new_node = (node*)malloc(sizeof(node));
  CHECK_ALLOC(new_node);
  node *right = *list;

  if (*list == NULL) {
    new_node->data = new_element;
    new_node->next = NULL;
    *list = new_node; 
  }
  
  else {
    if (position == 0){
      new_node->data = new_element;
	new_node->next = *list;
	*list = new_node; 
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
}

int list_remove(node** list, int position){
  node* left;
  node* right = *list;
  int removed_el;

  if (!*list)
    return -1;

  if (!(*list)->next) {
    removed_el = (*list)->data;
    free(*list);
    *list = NULL;
    return removed_el;
  }
    
  else {
    if (position == 0){
      removed_el = (*list)->data; 
      *list = (*list)->next; 
      free(right);
    }
    else {
      for (int i = 0; i < position; ++i){
	left = right;
	right = right->next;
      }
      left->next = right->next;
      removed_el = right->data;
      free(right);
    }
    return removed_el;
  }
}
  
void test_list_create(void) {
  node* list = list_create(1);
  
  ASSERT(list->data == 1);
  
  list_free(list);
}


void test_list_append(void) {
  node* list = list_create(1);
  
  list_append(&list, 2);
  
  ASSERT(list->data == 1);
  ASSERT(list->next->data == 2);
  
  list_free(list);
}

void test_list_append_many(void) {
  node* list = list_create(0); 
  ASSERT(list->data == 0);
  
  node* iterator = list;
  for(int i=1; i<15; ++i) {
    list_append(&list, i);
	iterator = iterator->next;
	ASSERT(iterator->data == i);
      }
      list_free(list);
}

void test_append_to_empty() {
  node* head = NULL;
  list_append(&head, 1);
  ASSERT(head != NULL);
  ASSERT(head->data == 1);
  ASSERT(head->next == NULL);
  list_free(head);
}

void test_list_pop(void) {
  node* list = list_create(1); 
  ASSERT(list_pop(list) == 1); 
  list = NULL;
}

void test_list_insert(void){
  node* list = list_create(0); 
  node* iterator = list;
  for(int i=1; i<5; ++i) {
    list_append(&list, i);
    iterator = iterator->next; 
  }
  list_insert(&list, 16, 2);
  ASSERT(list->next->next->data == 16);
  list_free(list);
}

void test_list_insert_to_empty(void){
  node* head = NULL;
  list_insert(&head, 2, 0);
  ASSERT(head != NULL);
  ASSERT(head->data == 2);
  ASSERT(head->next == NULL);
  list_free(head);
}

/* void test_list_remove(void){ //todo
   node* list = list_create(100); 
   node* iterator = list;
   for(int i=1; i<7; ++i) {
   list_append_element_end(list, i);
   iterator = iterator->next; 
   } 
   }
*/

int main(void){
  test_list_create();
  test_list_append();
  test_list_append_many(); 
  test_append_to_empty();
  test_list_pop();
  test_list_insert();
  test_list_insert_to_empty();
  //test_list_remove();

  return 0;
}
