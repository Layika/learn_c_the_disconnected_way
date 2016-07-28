#include <stdio.h>
#include "double_linked_list.h"

int main(){
    list* l = list_create();

    list_prepend(l, 1);
    list_prepend(l, 0);
    list_print(l);

    list_append(l, 2);
    list_append(l, 3);
    list_append(l, 4);
    list_append(l, 5);
    list_print(l);

    int popped = list_pop(l);
    printf("Popped element: %d\n", popped);
    list_print(l);

    int chosen_el = list_get_el(l, 5);
    printf("Element on chosen position is: %d\n", chosen_el);
    list_print(l);

    list_reverse(l);
    list_print(l);

    list_free(l);
    return 0;
}