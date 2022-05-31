/*
** EPITECH PROJECT, 2021
** my_showstr
** File description:
** my_showstr
*/

#include <unistd.h>

int my_char_isprintable(char const str);

int my_putnbr_base(int nbr, char const *base);

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (my_char_isprintable(str[i])) {
            write(1, &str[i], 1);
        } else {
            write(1, "\\", 2);
            my_putnbr_base(str[i], "0123456789abcdef");
        }
    }
    return (0);
}
