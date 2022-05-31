/*
** EPITECH PROJECT, 2021
** my_put_str_arr
** File description:
** my_put_str_arr
*/

#include <stdlib.h>

int my_putstr(char const *str);

void my_put_str_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        my_putstr(arr[i]);
}
