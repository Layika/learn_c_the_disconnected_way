#include <stdio.h>
#include "double_linked_list.h"

int main(){
    node* head = list_create();

    list_append(head, 2);
    list_append(head, 3);
    list_append(head, 4);
    list_append(head, 5);
    list_print(head);

    list_prepend(head, 1);
    list_prepend(head, 0);
    list_print(head);

    int popped = list_pop(head);
    printf("Popped element: %d\n", popped);
    list_print(head);

    int chosen_el = list_get_el(head, 5);
    printf("Element on chosen position is: %d\n", chosen_el);
    list_print(head);

    list_reverse(head);
    list_print(head);

    list_free(head);
    return 0;
}