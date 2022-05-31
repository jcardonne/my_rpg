/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage base type
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"
#include <stdarg.h>

char *type_octal(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_struint_base(value, result, "01234567",
    data->precision);
    if (data->active_flags[F_POS_PREFIX] && value != 0) {
        result = my_addchar(result, '0');
        data->prefix_len = 1;
    }
    my_revstr(result);
    return (result);
}

char *type_hexa(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_struint_base(value, result, "0123456789abcdef",
    data->precision);
    if (data->active_flags[F_POS_PREFIX] && value != 0) {
        result = my_addchar(result, 'x');
        result = my_addchar(result, '0');
        data->prefix_len = 2;
    }
    my_revstr(result);
    return (result);
}

char *type_hexa_upper(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_struint_base(value, result, "0123456789ABCDEF",
    data->precision);
    if (data->active_flags[F_POS_PREFIX] && value != 0) {
        result = my_addchar(result, 'X');
        result = my_addchar(result, '0');
        data->prefix_len = 2;
    }
    my_revstr(result);
    return (result);
}

char *type_binary(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_struint_base(value, result, "01", data->precision);
    my_revstr(result);
    return (result);
}

char *type_pointer(va_list args, printf_data_t *data)
{
    long value = va_arg(args, long);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strlong_base(value, result, "0123456789abcdef",
    data->precision);
    result = my_addchar(result, 'x');
    result = my_addchar(result, '0');
    data->prefix_len = 2;
    my_revstr(result);
    return (result);
}
