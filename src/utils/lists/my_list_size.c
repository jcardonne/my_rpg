/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** my_list_size
*/

#include "../../../include/mylist.h"

int my_list_size(linked_list_t *begin)
{
    linked_list_t *temp = begin;

    if (temp == NULL)
        return (0);
    else
        return (1 + my_list_size(temp->next));
}
