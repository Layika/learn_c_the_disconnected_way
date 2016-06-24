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


void list_free(node** head){
  node* current = *head;
  while (current != NULL)
    {
      node* tmp = current;
      current = current->next;
      free(tmp);
    }
  *head = NULL; 
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


int list_pop(node** list){
  int result;
  
  if (!(*list))
    return -1;

  if (!(*list)->next) {
    result = (*list)->data;
    free(*list);
    *list = NULL;
    return result;
  }
  else {
    node* prev_node = NULL;
    while ((*list)->next != NULL) {
      prev_node = *list;
      *list = (*list)->next; 
    } 
  
    if (prev_node)
      prev_node->next = NULL;

    result = (*list)->data; 
    free(*list);
    return result;
  }
}

void list_insert(node** list, int new_element, int position){
  node* new_node = (node*)malloc(sizeof(node));
  CHECK_ALLOC(new_node);
  
  new_node->data = new_element;

  if (*list == NULL) {
    new_node->next = NULL;
    *list = new_node; 
  }
  
  else if (position == 0) {
    new_node->next = *list;
    *list = new_node; 
  }
  
  else {
    node* prev = NULL;
    node* current = *list;
    int counter = 0;

    while (current->next) {
      prev = current;
	current = current->next; 
	++counter;
      
	if (counter == position){
	  prev->next = new_node;
	  new_node->next = current;
	  return;
	}
      }
      current->next = new_node;
    }
  }

  int list_remove(node** list, int position){
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
	node* temp = *list;
	removed_el = (*list)->data; 
	*list = (*list)->next; 
	free(temp);
      }
      else {
	int counter = 0;
	node* temp = *list;
	while (temp->next) {
	  temp = temp->next;
	  ++counter; 
	  if (counter == (position-1)) 
	    break; 
	} 
	if (temp->next->next == NULL){
	  removed_el = temp->next->data;
	  node* remove = temp->next;
	  temp->next = NULL;
	  free(remove);
	}
	else {
	  removed_el = temp->next->data;
	  node* remove = temp->next;
	  temp->next = temp->next->next;
	  free(remove);
	} 
      }
      return removed_el;
    }
  }

void list_reverse(node** list){
  if (!*list)
    printf("Can't reverse a null list.\n\n") ;

  else if (!(*list)->next) {
    return;
  }

  else {
    node* prev_node = NULL;
    node* next_node;
    node* tmp = *list;
    while(tmp->next){
      next_node = tmp->next;
      tmp->next = prev_node;
      prev_node = tmp;
      tmp = next_node;
    }
    tmp->next = prev_node;

    *list = tmp;
  }
}

void test_list_create(void) {
  node* list = list_create(1);
  
  ASSERT(list->data == 1);
  
  list_free(&list);
}


void test_list_append(void) {
  node* list = list_create(1);
  
  list_append(&list, 2);
  
  ASSERT(list->data == 1);
  ASSERT(list->next->data == 2);
  
  list_free(&list);
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
  list_free(&list);
}

void test_list_append_to_empty() {
  node* head = NULL;
  list_append(&head, 1);
  ASSERT(head != NULL);
  ASSERT(head->data == 1);
  ASSERT(head->next == NULL);
  list_free(&head);
}

void test_list_pop(void) {
  node* list = list_create(1); 
  ASSERT(list_pop(&list) == 1); 
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
  list_free(&list);
}

void test_list_insert_to_empty(void){
  node* head = NULL;
  list_insert(&head, 2, 0);
  ASSERT(head != NULL);
  ASSERT(head->data == 2);
  ASSERT(head->next == NULL);
  list_free(&head);
}

void test_list_insert_to_right_position(void){
  node* head = list_create(1);
  list_append(&head, 2); 
  list_insert(&head, 3, 1);
  ASSERT(head->data == 1);
  ASSERT(head->next->data == 3);
  ASSERT(head->next->next->data == 2);
  ASSERT(head->next->next->next == NULL);
  list_free(&head);
}

void test_list_remove(void){ 
  node* head = list_create(100); 
  list_append(&head, 1);
  list_append(&head, 2);
  list_append(&head, 3); 
  ASSERT(list_remove(&head, 2) == 2);
  ASSERT(head->next->next->data == 3);
  list_free(&head);
}

void test_list_reverse(void){
  node* list = list_create(0);

  for(int i=1; i<=10; ++i) {
    list_append(&list, i); 
  }
  
  list_reverse(&list);
  
  node* iterator = list;
  for (int i = 10; i >= 0; i--){
    ASSERT(iterator->data == i); 
    iterator = iterator->next; 
  }
  list_free(&list);
}


int main(void){
  test_list_create();
  test_list_append();
  test_list_append_many(); 
  test_list_append_to_empty();
  test_list_pop();
  test_list_insert();
  test_list_insert_to_empty();
  test_list_insert_to_right_position();
  test_list_remove();
  printf("reverse below:\n");
  test_list_reverse();
  
  return 0;
}
