/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** extend_str
*/

#include <stdlib.h>
#include "my.h"

char *extend_string(char *first, char *second)
{
    int len_first = my_strlen(first);
    int len_second = my_strlen(second);
    char *new = malloc(sizeof(char) * len_first + len_second + 1);
    int pos = 0;

    for (; *first; ++first) {
        new[pos++] = *first;
    }
    for (; *second; ++second) {
        new[pos++] = *second;
    }
    new[pos] = '\0';
    return new;
}

int is_quote(int c)
{
    return (c == '\'' || c == '"');
}

char *remove_quote(char *str)
{
    if (str == NULL)
        return NULL;
    int len = my_strlen(str);
    if (len == 0 || !(str[0] == str[len - 1] && is_quote(str[0])))
        return str;
    char *new_str = malloc(sizeof(char) * len);
    my_strcpy(new_str, &str[1]);
    new_str[len - 2] = '\0';
    free(str);
    return new_str;
}
