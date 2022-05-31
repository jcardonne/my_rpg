/*
** EPITECH PROJECT, 2021
** my_rev_str_list
** File description:
** my_rev_str_list
*/

#include <stdlib.h>

int my_arr_size(char **arr);

void my_rev_str_list(char **arr)
{
    char *temp = NULL;
    int end = my_arr_size(arr) - 1;

    for (int start = 0; start < end; start++) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        end--;
    }
}
