/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** free
*/

#include <stdlib.h>

void free_arr(char **arr)
{
    int i = 0;

    for (; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

void my_free(void)
{
}
