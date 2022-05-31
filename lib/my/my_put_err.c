/*
** EPITECH PROJECT, 2021
** my_put_err
** File description:
** my_put_err
*/

#include <unistd.h>

int my_put_err(char const * str)
{
    while (* str != '\0') {
        write(2, str++, 1);
    }
    return (0);
}

int my_put_err_two(char const * str, char const *str_two)
{
    my_put_err(str);
    my_put_err(str_two);
    return (0);
}
