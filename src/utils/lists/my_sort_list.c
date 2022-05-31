/*
** EPITECH PROJECT, 2021
** my_sort_list
** File description:
** Test
*/

#include "../../../include/mylist.h"

void my_sort_list_help(linked_list_t **begin, int (*cmp) ())
{
    char *next_data;

    while (begin != NULL) {
        if ((*begin)->next == NULL) {
            return;
        }
        if (cmp((*begin)->data, (*begin)->next->data) > 0) {
            next_data = (*begin)->next->data;
            (*begin)->next->data = (*begin)->data;
            (*begin)->data = next_data;
        }
        begin = &(*begin)->next;
    }
}

void my_sort_list(linked_list_t **begin , int (*cmp)())
{
    for (int i = 0; i < my_list_size(*begin); i++)
        my_sort_list_help(begin, (cmp));
}
