/*
** EPITECH PROJECT, 2021
** my_add_in_sorted_list
** File description:
** test
*/

#include "../../../include/mylist.h"

void my_add_in_sorted_list(linked_list_t **begin , void *data , int (*cmp)())
{
    my_put_in_list(begin, data);
    my_sort_list(begin, cmp);
}
