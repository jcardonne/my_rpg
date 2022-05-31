/*
** EPITECH PROJECT, 2021
** my_itoa
** File description:
** my_itoa
*/

#include <stdlib.h>

int my_nbrlen(int number);
char *my_revstr(char *str);

char *my_int_to_strnum(int nb)
{
    char *result = malloc(sizeof(char) * my_nbrlen(nb) + 2);
    unsigned int i = 0;
    if (nb < 0) {
        if (nb == -2147483648)
            return ("-2147483648");
        nb *= -1;
    } else if (nb == 0)
        return ("0");
    while (nb != 0) {
        result[i++] = nb % 10 + '0';
        nb = nb / 10;
    }
    if (nb < 0)
        result[i++] = '-';
    result[i] = '\0';
    return (my_revstr(result));
}
