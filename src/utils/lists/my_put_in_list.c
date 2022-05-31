/*
** EPITECH PROJECT, 2021
** my_put_in_list
** File description:
** my_put_in_list
*/

#include "../../../include/mylist.h"

int my_put_in_list(struct linked_list **list, void *data)
{
    struct linked_list *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return (0);
}
