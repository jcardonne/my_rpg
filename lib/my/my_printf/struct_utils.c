/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** flag_funcs
*/

#include "include/flags.h"
#include "include/arg_type.h"
#include "../my.h"

int get_flag_pos(char c)
{
    int i = 0;

    for (; FLAG_LIST[i] != '\0' ; ++i)
        if (FLAG_LIST[i] == c)
            return (i);
    return (-1);
}

arg_type_t get_type(const char *str)
{
    int i = 0;

    for (; ARG_TYPE_LIST[i].sign != NULL ; ++i) {
        if (my_strncmp(str, ARG_TYPE_LIST[i].sign, ARG_TYPE_LIST[i].len) == 0)
            return (ARG_TYPE_LIST[i]);
    }
    return (ARG_TYPE_LIST[i]);
}

printf_data_t *create_data_struct(void)
{
    printf_data_t *data = malloc(sizeof(printf_data_t));

    for (int i = 0 ; i < 5 ; ++i)
        data->active_flags[i] = 0;
    data->str = "";
    data->prefix_len = 0;
    data->min_field_width = 0;
    data->precision = -1;
    data->is_nb = 0;
    return (data);
}
