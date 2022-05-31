/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/flags.h"
#include "include/my_printf.h"
#include "../my.h"
#include "include/arg_type.h"

int get_flag_pos(char c);
arg_type_t get_type(const char *str);
printf_data_t *create_data_struct(void);
int flag_handling(const char *format, printf_data_t *data);
int type_handling(const char *format, printf_data_t *data, va_list args);
int min_width_handling(const char *format, printf_data_t *data, va_list args);
int precision_handling(const char *format, printf_data_t *data, va_list args);

void replace_n_char(char *str, char c, int n)
{
    for (int i = 0 ; str[i] != '\0' && i < n ; ++i)
        str[i] = c;
}

int show_data(int fd, printf_data_t *data)
{
    int i = 0;
    char *to_free = data->str;
    char symbol = ' ';

    if (data->active_flags[F_POS_LEFT_JUSTIFY])
        my_putstr_stream(fd, data->str);
    if (!data->active_flags[F_POS_LEFT_JUSTIFY] && data->precision == -1
    && data->active_flags[F_POS_ZERO_PADDED] && data->is_nb) {
        i += data->prefix_len;
        write(fd, data->str, data->prefix_len);
        data->str += data->prefix_len;
        symbol = '0';
    }
    for (; i < data->min_field_width - my_strlen(data->str) ; ++i)
        write(fd, &symbol, 1);
    if (!data->active_flags[F_POS_LEFT_JUSTIFY])
        my_putstr_stream(fd, data->str);
    int result = MAX(data->min_field_width, my_strlen(data->str));
    free(to_free);
    return (result);
}

int format_identifier(int fd, const char *format,
va_list args, int *written)
{
    int i = 0;
    int type_size = 0;
    printf_data_t *data = create_data_struct();

    i += flag_handling(&format[i], data);
    i += min_width_handling(&format[i], data, args);
    i += precision_handling(&format[i], data, args);
    type_size = type_handling(&format[i], data, args);
    if (type_size <= 0) {
        free(data);
        return (0);
    }
    *written += show_data(fd, data);
    free(data);
    return (i + type_size + 1);
}

int my_printf_parser(int fd, const char *format, va_list args)
{
    int i = 0;
    int format_len = 0;
    int written = 0;
    int last_write = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            write(fd, &format[last_write], i - last_write);
            written += i - last_write;
            format_len = format_identifier(fd,
            &format[i + 1], args, &written);
            i += format_len;
            last_write = i;
            i += format_len == 0;
        } else
            ++i;
    }
    write(fd, &format[last_write], i - last_write);
    written += i - last_write;
    return (written);
}

int my_printf(const char *format, ...)
{
    int printed = 0;

    va_list args;
    va_start(args, format);

    printed = my_printf_parser(1, format, args);
    va_end(args);
    return (printed);
}
