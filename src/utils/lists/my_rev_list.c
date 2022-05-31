/*
** EPITECH PROJECT, 2021
** my_rev_list
** File description:
** my_rev_list
*/

#include "../../../include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
    struct linked_list *before = NULL;
    struct linked_list *next = NULL;
    struct linked_list *actual = *begin;

    while (actual != NULL) {
        next = actual->next;
        actual->next = before;
        before = actual;
        actual = next;
    }
    *begin = before;
}
