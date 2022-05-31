/*
** EPITECH PROJECT, 2021
** my_char_is_nbr
** File description:
** my_char_is_nbr
*/

int my_char_is_nbr(char s)
{
    int c = 0;

    c = (s >= 48 && s <= 57);
    if (!c)
        return (0);
    return (1);
}
