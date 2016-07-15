#include <stdio.h>
#include "test.h"
#include "double_linked_list.h"

void test_list_prepend() {
    node* head = list_create();
    list_prepend(head, 0);
    list_prepend(head, 1);
    ASSERT(head->data == 1);
    list_free(head);
}

void test_list_append(){
    node* head = list_create();
    list_append(head, 100);
    list_append(head, 10);
    ASSERT(head->next->data == 10);
    list_free(head);
}

void test_list_pop(){
    node* head = list_create();
    list_prepend(head, 0);
    list_prepend(head, 1);
    int popped = list_pop(head);
    ASSERT(popped == 0);
    list_free(head);
}

void test_list_reverse(){
    node* head = list_create();
    for (int i = 0; i < 6; ++i){
        list_append(head, i);
    }
    list_reverse(head);
    node* tmp = head;
    while(tmp->next) {
        for (int i = 5; i >= 0; --i) {
            ASSERT(tmp->data == i);
            tmp = tmp->next;
        }
    }
    list_free(head);
}

void test_list_get_el(){
    node* head = list_create();
    list_prepend(head, 1);
    list_prepend(head, 0);
    int chosen_el = list_get_el(head, 1);
    ASSERT(chosen_el == 1);
    ASSERT(head->next->data == 1);
    list_free(head);
}