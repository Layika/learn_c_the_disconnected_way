#pragma once

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node* list_create();
void list_free(node* head);
void list_print(node* head);
void list_prepend(node* head, int new_elem);
void list_append(node* head, int new_elem);
int list_pop(node* head);
void list_reverse(node* head);
int list_get_el(node* head, int pos);