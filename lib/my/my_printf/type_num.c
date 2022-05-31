/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage num type
*/

#include "include/my_printf.h"
#include "../my.h"
#include <stdarg.h>

char *type_decimal(va_list args, printf_data_t *data)
{
    int value = va_arg(args, int);
    char *result = my_strdup("");
    char sign = get_sign_char(value < 0, data);

    data->is_nb = 1;
    result = my_strint_base(value, result, "0123456789", data->precision);
    result = my_addchar(result, sign);
    data->prefix_len = sign != '\0';
    my_revstr(result);
    return (result);
}

char *type_unsigned_int(va_list args, printf_data_t *data)
{
    unsigned int value = va_arg(args, unsigned int);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_struint_base(value, result, "0123456789", data->precision);
    my_revstr(result);
    return (result);
}

char *type_long(va_list args, printf_data_t *data)
{
    long value = va_arg(args, long);
    char *result = my_strdup("");
    char sign = get_sign_char(value < 0, data);

    data->is_nb = 1;
    result = my_strlong_base(value, result, "0123456789", data->precision);
    result = my_addchar(result, sign);
    data->prefix_len = sign != '\0';
    my_revstr(result);
    return (result);
}

char *type_unsigned_long(va_list args, printf_data_t *data)
{
    unsigned long value = va_arg(args, unsigned long);
    char *result = my_strdup("");

    data->is_nb = 1;
    result = my_strulong_base(value, result, "0123456789", data->precision);
    my_revstr(result);
    return (result);
}
