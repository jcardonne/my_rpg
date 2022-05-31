/*
** EPITECH PROJECT, 2021
** str_utils.c
** File description:
** str_utils
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"

char get_sign_char(int is_neg, printf_data_t *data)
{
    if (is_neg)
        return ('-');
    else {
        if (data->active_flags[F_POS_SHOW_POSITIVE])
            return ('+');
        if (data->active_flags[F_POS_BLANK_POSITIVE])
            return (' ');
    }
    return ('\0');
}

char *my_addchar(char *src, char c)
{
    int len = my_strlen(src);
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 2));

    for (; src[i] != '\0' ; ++i)
        dest[i] = src[i];
    dest[i] = c;
    dest[i + 1] = '\0';
    free(src);
    return dest;
}
