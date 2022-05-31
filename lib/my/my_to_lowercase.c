/*
** EPITECH PROJECT, 2021
** my_to_lowercase
** File description:
** my_to_lowercase
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_to_lowercase(const char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            result[i] = str[i] + 32;
        } else {
            result[i] = str[i];
        }
    }
    return (result);
}
