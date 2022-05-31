/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** t
*/

void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int base_ln = my_strlen(base);
    int temp = 0;

    if (nbr < 0) {
        my_putchar(45);
        nbr *= -1;
    }
    if (nbr > 0) {
        temp = nbr % base_ln;
        nbr /= base_ln;
        my_putnbr_base(nbr, base);
        my_putchar(base[temp]);
    }
    return (0);
}
