/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All functions to manage float type
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"
#include <stdarg.h>

char *my_strfloat_int(double nbr, char *str, int round_int)
{
    int new_nbr = (int)nbr;
    int carry = round_int;
    unsigned int remainder = 0;
    char *str_ptr = str;

    if (nbr == 0)
        return (my_addchar(str, '0'));
    while (new_nbr != 0) {
        remainder = (new_nbr + carry) % 10;
        carry = carry && remainder == 0;
        new_nbr /= 10;
        str_ptr = my_addchar(str_ptr, remainder + '0');
    }
    return (str_ptr);
}

char *my_strfloat_decimal(double nbr, char *str, int precision)
{
    int new_nbr = (int)nbr;
    new_nbr = (int)((nbr - new_nbr) * power(10, precision + 1));
    int carry = new_nbr % 10 >= 5;
    new_nbr /= 10;
    unsigned int remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str, '0'));
    while (new_nbr != 0 || precision > 0) {
        remainder = (new_nbr + carry) % 10;
        carry = carry && remainder == 0;
        new_nbr /= 10;
        str_ptr = my_addchar(str_ptr, remainder + '0');
        precision--;
    }
    return (str_ptr);
}

char *type_float(va_list args, printf_data_t *data)
{
    double value = va_arg(args, double);
    char *result = my_strdup("");
    int round_int = 0;
    int precision = MIN(data->precision == -1 ? 6 : data->precision, 6);
    int is_neg = value < 0;

    value = is_neg ? -value : value;
    data->is_nb = 1;
    if (precision == 0) {
        round_int = (int)(value * 10) % 10 >= 5;
    } else {
        result = my_strfloat_decimal(value, result, precision);
        result = my_addchar(result, '.');
    }
    result = my_strfloat_int(value, result, round_int);
    result = my_addchar(result, get_sign_char(is_neg, data));
    data->prefix_len = get_sign_char(is_neg, data) != '\0';
    data->precision = -1;
    my_revstr(result);
    return (result);
}
