/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** Display positive or negative number
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
    return (0);
}
