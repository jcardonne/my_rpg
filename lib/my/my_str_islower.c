/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    int i = 0;
    int check = 0;

    while (str[i] != '\0') {
        check = str[i] >= 97 && str[i] <= 122;
        if (!check)
            return (0);
        i++;
    }
    return (1);
}
