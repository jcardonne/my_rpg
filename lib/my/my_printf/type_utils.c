/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** All utils for type funcs
*/

#include "include/my_printf.h"
#include "../my.h"
#include "include/flags.h"

char *my_addchar(char *src, char c);
char get_sign_char(int is_neg, printf_data_t *data);

char *my_strint_base(int nbr, char *str, char const *base, int precision)
{
    int len_base = my_strlen(base);
    int new_nbr = nbr;
    int remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str_ptr, base[0]));
    while (new_nbr != 0 || precision > 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_struint_base(unsigned int nbr, char *str, char const *base,
int precision)
{
    int len_base = my_strlen(base);
    unsigned int new_nbr = nbr;
    unsigned int remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str_ptr, base[0]));
    while (new_nbr != 0 || precision > 0) {
        remainder = new_nbr % len_base;
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_strlong_base(long nbr, char *str, char const *base, int precision)
{
    int len_base = my_strlen(base);
    long new_nbr = nbr;
    long remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str_ptr, base[0]));
    while (new_nbr != 0 || precision > 0) {
        remainder = ABS(new_nbr % len_base);
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}

char *my_strulong_base(unsigned long nbr, char *str, char const *base,
int precision)
{
    int len_base = my_strlen(base);
    unsigned long new_nbr = nbr;
    unsigned long remainder = 0;
    char *str_ptr = str;

    if (nbr == 0 && precision == -1)
        return (my_addchar(str_ptr, base[0]));
    while (new_nbr != 0 || precision > 0) {
        remainder = new_nbr % len_base;
        new_nbr /= len_base;
        str_ptr = my_addchar(str_ptr, base[remainder]);
        precision--;
    }
    return (str_ptr);
}
