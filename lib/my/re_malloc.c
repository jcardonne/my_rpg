/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** re_malloc
*/

#include <stdlib.h>

char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);

char *re_malloc(char *str)
{
    if (str == NULL)
        return (NULL);
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    new_str[0] = '\0';
    my_strcat(new_str, str);
    free(str);
    return (new_str);
}
