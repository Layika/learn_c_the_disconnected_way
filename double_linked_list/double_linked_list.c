#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_linked_list.h"

list* list_create(){
    list* l = (list*)malloc(sizeof(list));
    l->quantity = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void list_free(list* l){
    node* first = l->head;
    while (first->next) {
            node *second = first;
            first = first->next;
            free(second);
    }
    free(l);
}

void list_print(list* l){
    if (!l)
        printf("Empty list!\n");
    else{
        node* tmp = l->head;
        printf("[ ");
        while (tmp){
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("]\n");
    }
}

void list_prepend(list* l, int new_elem) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_elem;
    new_node->next = l->head;
    new_node->prev = NULL;
    if (l->head)
        l->head->prev = new_node;
    l->head = new_node;
    if (!l->head->next)
        l->tail = l->head;
    l->quantity += 1;
}

bool list_append(list* l, int new_elem){
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node)
        return false;
    new_node->data = new_elem;
    new_node->prev = l->tail;
    new_node->next = NULL;
    if (!l->head)
        l->head =  new_node;
    else
        l->tail->next = new_node;
    l->tail = new_node;
    l->quantity += 1;
    return true;
}

int list_pop(list* l){
    l->quantity -= 1;
    node* tmp = l->tail;
    int ret_el = tmp->data;
    free(tmp);
    if (l->quantity < 2)
        l->tail = l->head;
    return ret_el;
}

void list_reverse(list* l){
    if (!l->tail)
        return;
    else {
        node* tmp = l->head;
        l->head = l->tail;
        l->tail = tmp;

        node* iter = l->head->prev;
        tmp = l->head;
        node* change = iter;
        node* help = iter;
        while(iter->prev) {
            change->prev = change->next;
            change->next = help->prev;

            iter = iter->prev;
            change = iter;
            help = iter;
        }
        tmp->next = tmp->prev;
        tmp->prev = NULL;
    }
}

int list_get_el(list* l, int pos){
    int chosen_el;
    int quantity = l->quantity;
    if (!l->tail || pos == 0){
        chosen_el = l->head->data;
    }
    else if (pos <= quantity/2){
        int counter = 0;
        node* iter = l->head;
        while(iter->next){
            iter = iter->next;
            ++counter;
            if (counter == pos)
                break;
        }
        chosen_el = iter->data;
    }
    else if (pos > quantity/2){
        int counter = 0;
        node* iter = l->tail;
        while(iter->prev){
            iter = iter->prev;
            ++counter;
            if (counter == pos)
                break;
        }
        chosen_el = iter->data;
    }
    else if (pos > quantity)
        chosen_el = l->tail->data;
    return chosen_el;
}