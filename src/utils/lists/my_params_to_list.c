/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** my_params_to_list
*/

#include "../../../include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    struct linked_list **list = malloc(sizeof(struct linked_list *));

    *list = NULL;
    for (int i = 0; i < ac; i++) {
        my_put_in_list(list, av[i]);
    }
    return *list;
}
