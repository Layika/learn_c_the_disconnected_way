#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_linked_list.h"

list* list_create(){
    list* l = (list*)malloc(sizeof(list));
    if (l == NULL)
        return NULL;
    l->quantity = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void list_free(list* l) {
    if (l->quantity > 0) {
        node* current = l->head;
        node* next = l->head->next;

        while(next) {
            free(current);
            current = next;
            next = next->next;
        }

        // deallocating last element
        free(current);
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

bool list_prepend(list* l, int new_elem) {
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node)
        return false;
    new_node->data = new_elem;
    new_node->next = l->head;
    new_node->prev = NULL;
    if (l->head)
        l->head->prev = new_node;
    l->head = new_node;
    if (!l->head->next)
        l->tail = l->head;
    l->quantity += 1;
    return true;
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

int list_pop(list* l) {
    node *tmp = l->tail;
    int ret_el = tmp->data;
    if (l->quantity > 1) {
        l->tail = l->tail->prev;
        l->tail->next = NULL;
        free(tmp);
    }
    l->quantity -= 1;
    if (l->quantity == 1)
        l->tail = l->head;
    else if (l->quantity == 0) {
        l->tail = l->head = NULL;
        free(tmp);
    }
    return ret_el;
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
        pos = l->quantity - pos;
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

void list_reverse(list* l){
    if (l->tail == l->head || l->head == NULL)
        return;
    else {
        node* tmp = l->head;
        l->head = l->tail;
        l->tail = tmp;
        node* iter = l->head;
        node* temp = l->head->prev;
        node* holder;
        l->head->next = l->head->prev;
        l->head->prev = NULL;
        while(iter->next) {
            holder = temp->next;
            temp->next = temp->prev;
            temp->prev = holder;
            iter = temp;
            temp = temp->next;
        }
    }
}