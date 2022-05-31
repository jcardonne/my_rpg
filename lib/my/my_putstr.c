/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Print string
*/

#include <unistd.h>

int my_putstr(char const * str)
{
    while (* str != '\0') {
        write(1, str++, 1);
    }
    return (0);
}
