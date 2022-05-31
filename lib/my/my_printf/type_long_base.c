/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage long base type
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"
#include <stdarg.h>

char *type_long_octal(va_list args, printf_data_t *data)
{
    unsigned long value = va_arg(args, unsigned long);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strulong_base(value, result, "01234567",
    data->precision);
    if (data->active_flags[F_POS_PREFIX] && value != 0) {
        result = my_addchar(result, '0');
        data->prefix_len = 1;
    }
    my_revstr(result);
    return (result);
}

char *type_long_hexa(va_list args, printf_data_t *data)
{
    unsigned long value = va_arg(args, unsigned long);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strulong_base(value, result, "0123456789abcdef",
    data->precision);
    if (data->active_flags[F_POS_PREFIX] && value != 0) {
        result = my_addchar(result, 'x');
        result = my_addchar(result, '0');
        data->prefix_len = 2;
    }
    my_revstr(result);
    return (result);
}

char *type_long_hexa_upper(va_list args, printf_data_t *data)
{
    unsigned long value = va_arg(args, unsigned long);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strulong_base(value, result, "0123456789ABCDEF",
    data->precision);
    if (data->active_flags[F_POS_PREFIX] && value != 0) {
        result = my_addchar(result, 'X');
        result = my_addchar(result, '0');
        data->prefix_len = 2;
    }
    my_revstr(result);
    return (result);
}

char *type_long_binary(va_list args, printf_data_t *data)
{
    unsigned long value = va_arg(args, unsigned long);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strulong_base(value, result, "01", data->precision);
    my_revstr(result);
    return (result);
}
