/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str);

int my_putstr_stream(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
    return (0);
}
