/*
** EPITECH PROJECT, 2021
** my_concat_list
** File description:
** my_concat_list
*/

#include "../../../include/mylist.h"

void my_concat_list(linked_list_t **begin1 , linked_list_t *begin2)
{
    if ((*begin1)->next == NULL)
        (*begin1)->next = begin2;
    else
        my_concat_list(&(*begin1)->next, begin2);
}
