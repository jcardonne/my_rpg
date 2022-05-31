/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_fprintf
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/flags.h"
#include "include/my_printf.h"
#include "../my.h"
#include "include/arg_type.h"

int my_printf_parser(int fd, const char *format, va_list args);

int my_fprintf(int fd, const char *format, ...)
{
    int printed = 0;

    va_list args;
    va_start(args, format);

    printed = my_printf_parser(fd, format, args);
    va_end(args);
    return (printed);
}
