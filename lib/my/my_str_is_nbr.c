/*
** EPITECH PROJECT, 2022
** dante
** File description:
** my_str_is_nbr
*/

int my_char_is_nbr(char s);

int my_str_is_nbr(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (my_char_is_nbr(str[i]) == 0)
            return (0);
    }
    return (1);
}
