#pragma once

#include <stdbool.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

typedef struct list {
    node* head;
    node* tail;
    int quantity;
} list;

list* list_create();
void list_free(list* list);
void list_print(list* list);
void list_prepend(list* list, int new_elem);
bool list_append(list* list, int new_elem);
int list_pop(list* list);
void list_reverse(list* list);
int list_get_el(list* list, int pos);