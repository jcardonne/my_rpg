/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

#include <stdlib.h>

int my_strlen(char const * str)
{
    int result = 0;

    if (str[0] == '\0' || str == NULL)
        return (0);
    while (str[result] != '\0') {
        result++;
    }
    return (result);
}
