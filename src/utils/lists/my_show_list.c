/*
** EPITECH PROJECT, 2021
** my_show_list
** File description:
** my_show_list
*/

#include "../../../include/mylist.h"

int my_putstr(char const *str);
void my_putchar(char c);

void my_show_list(struct linked_list *list)
{
    struct linked_list *temp;

    temp = list;
    while (temp != NULL) {
        my_putstr(temp->data);
        temp = temp->next;
        if (temp != NULL)
            my_putstr("  ");
    }
    my_putchar('\n');
}
