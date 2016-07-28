#include "test.h"

int main(){

    test_list_create();
    test_list_prepend();
    test_list_append();
    test_list_pop();
    test_list_pop_one_elem_list();
    test_list_get_el();
    test_list_reverse();
    test_list_get_el_pos_bigger_than_half();
    return 0;
}