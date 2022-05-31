/*
** EPITECH PROJECT, 2022
** mylist
** File description:
** mylist
*/

#ifndef MYLIST_H_
    #define MYLIST_H_

    #include <stdlib.h>

    typedef struct linked_list {
        void *data;
        struct linked_list *next;
    } linked_list_t;

    void my_rev_list(linked_list_t **begin);
    int my_list_size(linked_list_t *begin);
    void my_show_list(linked_list_t *list);
    int my_put_in_list(linked_list_t **list, void *data);
    void my_sort_list(linked_list_t **begin , int (*cmp)());

#endif
