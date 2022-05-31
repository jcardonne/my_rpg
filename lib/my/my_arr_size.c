/*
** EPITECH PROJECT, 2021
** my_arr_size.c
** File description:
** my_arr_size
*/

#include <stdlib.h>

int my_arr_size(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return (i);
}
