/*
** EPITECH PROJECT, 2021
** my_get_nbr_base
** File description:
** my_get_nbr_base
*/

#include <stdlib.h>
#include "my.h"

void my_putchar(char c);

int my_strlen(char const *str);

int compute(char const *base, char *str, int *i, long *temp_two)
{
    int base_ln = my_strlen(base);
    long temp;
    unsigned int nbr = *temp_two;

    if (base_ln <= 0)
        return (84);
    if (nbr < 0) {
        my_putchar(45);
        nbr *= -1;
    }
    temp = nbr % base_ln;
    nbr /= base_ln;
    *temp_two = nbr;
    if (nbr != 0)
        compute(base, str, i, temp_two);
    str[*i] = base[temp];
    *i = *i + 1;
    return (0);
}

char *my_get_nbr_base(long nbr, char *base)
{
    char *result = malloc(sizeof(char) * (21 + 1));
    int i = 0;

    compute(base, result, &i, &nbr);
    result[i] = '\0';
    return (result);
}
