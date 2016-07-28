#include <stdio.h>
#include <stdbool.h>
#include "test.h"
#include "double_linked_list.h"

void test_list_create(){
    list* l = list_create();

    ASSERT(l->head == NULL);
    ASSERT(l->tail == NULL);

    list_free(l);
}

void test_list_prepend() {
    list* l = list_create();
    list_prepend(l, 0);

    ASSERT(l->head == l->tail);
    ASSERT(l->head->data == 0);
    ASSERT(l->head->next == NULL);
    ASSERT(l->head->prev == NULL);

    list_prepend(l, 1);

    ASSERT(l->head != l->tail);
    ASSERT(l->head->data == 1);
    ASSERT(l->head->next->data == 0);
    ASSERT(l->head->prev == NULL);

    list_free(l);
}

void test_list_append(){
    list* l = list_create();
    int result = list_append(l, 100);

    ASSERT(result != 0);
    ASSERT(l->head == l->tail);
    ASSERT(l->head->data == 100);
    ASSERT(l->head->next == NULL);
    ASSERT(l->head->prev == NULL);

    list_append(l, 10);

    ASSERT(l->head != l->tail);
    ASSERT(l->head->data == 100);
    ASSERT(l->head->next->data == 10);
    ASSERT(l->tail->next == NULL);

    list_free(l);
}

void test_list_pop(){
    list* l = list_create();
    list_prepend(l, 0);
    list_prepend(l, 1);
    int popped = list_pop(l);

    ASSERT(popped == 0);
    ASSERT(l->head->data == 1);
    ASSERT(l->head == l->tail);

    list_free(l);
}

void test_list_pop_one_elem_list(){
    list* l = list_create();
    list_prepend(l, 0);
    int popped = list_pop(l);

    ASSERT(popped == 0);
    ASSERT(l->head == NULL);
    ASSERT(l->head == l->tail);

    list_free(l);
}

void test_list_get_el(){
    list* l = list_create();
    list_prepend(l, 1);
    list_prepend(l, 0);
    int chosen_el = list_get_el(l, 1);

    ASSERT(chosen_el == 1);
    ASSERT(l->tail->data == 1);

    list_free(l);
}


void test_list_reverse(){
    list* l = list_create();
    for (int i = 5; i >= 0; --i){
        list_append(l, i);
    }
    list_reverse(l);

    node* tmp = l->head;
    ASSERT(tmp->data == 0);
    tmp = tmp->next;
    ASSERT(tmp->data == 1);
    tmp = tmp->next;
    ASSERT(tmp->data == 2);
    tmp = tmp->next;
    ASSERT(tmp->data == 3);
    tmp = tmp->next;
    ASSERT(tmp->data == 4);
    tmp = tmp->next;
    ASSERT(tmp->data == 5);
    tmp = tmp->next;

    list_free(l);
}

void test_list_get_el_pos_bigger_than_half(){
    list* l = list_create();
    for (int i = 6; i >= 0; --i){
        list_prepend(l, i);
    };
    int chosen_el = list_get_el(l, 5);

    ASSERT(chosen_el == 4);
    list_free(l);
}