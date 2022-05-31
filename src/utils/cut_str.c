/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

int is_quote(int c);
char *remove_quote(char *str);

static void extend_array(char ***array, char *new_line)
{
    int size = 0;
    for (; (*array)[size] != NULL; ++size);
    char **new_array = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; i < size; ++i)
        new_array[i] = (*array)[i];
    new_array[size] = new_line;
    new_array[size + 1] = NULL;
    free(*array);
    *array = new_array;
}

static int char_in_str(char c, const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == c)
            return 1;
    return 0;
}

int quote_handling(char ***array, const char *str)
{
    char quote = str[0];
    int size = 1;

    for (; str[size] != quote; ++size)
        if (str[size] == '\0') {
            return (size);
        }
    size++;
    char *new_str = malloc(sizeof(char) * (size + 1));
    my_strncpy(new_str, str, size);
    new_str[size] = '\0';
    extend_array(array, remove_quote(new_str));
    return (size);
}

int handle_char(char ***array, char *str, char *delim)
{
    if (is_quote(str[0]))
        return (quote_handling(array, str));
    if (char_in_str(str[0], delim))
        return 1;
    int size = 0;
    for (; str[size] != '\0' && !char_in_str(str[size], delim); ++size);
    char *new_str = malloc(sizeof(char) * (size + 1));
    my_strncpy(new_str, str, size);
    new_str[size] = '\0';
    extend_array(array, new_str);
    return (size);
}

char **cut_str(char *str, char *delim)
{
    char **array = malloc(sizeof(char *));
    array[0] = NULL;
    int len = my_strlen(str);
    int tmp;
    for (int i = 0; i < len;) {
        tmp = handle_char(&array, &str[i], delim);
        if (tmp == -1)
            return NULL;
        i += tmp;
    }
    return array;
}
