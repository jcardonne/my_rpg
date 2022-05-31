/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int check = 0;

    while (str[i] != '\0') {
        check = str[i] >= 31 && str[i] < 127;
        if (!check)
            return (0);
        i++;
    }
    return (1);
}
