/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int check = 0;

    while (str[i] != '\0') {
        check = str[i] >= 48 && str[i] <= 57;
        if (!check)
            return (0);
        i++;
    }
    return (1);
}
