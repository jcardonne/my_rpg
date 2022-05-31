/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** strings_three
*/

#include <stdlib.h>
#include "my.h"

char **my_arr_copy(char **map)
{
    char **new_map = malloc(sizeof(char *) * (my_arr_size(map) + 1));
    int i = 0;

    if (new_map == NULL) {
        my_put_err("Error: malloc failed\n");
        return (NULL);
    }

    for (; map[i]; i++) {
        new_map[i] = malloc(sizeof(char) * (my_strlen(map[i]) + 1));
        new_map[i][0] = '\0';
        new_map[i] = my_strcat(new_map[i], map[i]);
    }
    new_map[i] = NULL;
    return (new_map);
}
