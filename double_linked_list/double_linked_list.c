#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

node* list_create(){
    node* head = (node*)malloc(sizeof(node));
    return head;
}

void list_free(node* head){
    node* first = head;
    while (first->next) {
            node *second = first;
            first = first->next;
            free(second);
    }
    head = NULL;
}

void list_print(node* head){
    if (!head)
        printf("Empty list!\n");
    else{
        node* tmp = head;
        node* next_node = tmp->next;
        printf("[ ");
        while (tmp->next){
            printf("%d ", next_node->data);
            tmp = tmp->next;
            next_node = next_node->next;
        }
        printf("]\n");
    }
}

void list_prepend(node* head, int new_elem) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_elem;
    new_node->next = head;
    new_node->prev = NULL;
    head->prev = new_node;
    head = new_node;
}

void list_append(node* head, int new_elem){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_elem;
    new_node->prev = NULL;
    new_node->next = NULL;

        while(head->next)
            head = head->next;
        head->next = new_node;
        new_node->prev = head;
}

int list_pop(node* head){
    node* tmp = head;
    node* prev_node = NULL;
    while (tmp->next) {
            prev_node = tmp;
            tmp = tmp->next;
    }
    prev_node->next = NULL;
    int ret_el = tmp->data;
    free(tmp);
    return ret_el;
}

void list_reverse(node* head){
    if (!head->next)
        return;
    else {
        while (head->next)
            head = head->next;
        node* tmp = head->next;
        node* change = tmp;
        while (tmp->prev) { // here
            change = tmp;
            change->next = tmp->prev;
            change->prev = tmp->next;
            tmp = tmp->prev;
        }
        while (change->prev)
            change = change->prev;
        head = change;
    }
}

int list_get_el(node* head, int pos){
    int chosen_el;
    if (!head->next || pos == 0){
        chosen_el = head->data;
    }
    else {
        int counter = 0;
        node* tmp = head;
        while (tmp->next) {
            ++counter;
            if (counter == pos)
                break;
            chosen_el = tmp->data;
        }
    }
    return chosen_el;
}