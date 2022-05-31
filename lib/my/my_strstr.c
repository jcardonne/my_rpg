/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** my_strstr
*/

#include <stdlib.h>

int my_strlen(char const * str);

char *my_strstr(char *str, char const *to_find)
{
    int str_ln = my_strlen(str);
    int to_find_ln = my_strlen(to_find);
    int to_find_index = 0;

    for (int i = 0; i < str_ln; i++) {
        if (str[i] == to_find[to_find_index]) {
            to_find_index++;
        } else if (to_find_index != 0) {
            to_find_index = 0;
        }

        if (to_find_index == to_find_ln) {
            return to_find_ln > 1 ? (&str[i - 1]) : (&str[i]);
        }
    }
    return (NULL);
}
