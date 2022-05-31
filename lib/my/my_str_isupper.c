/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** my_str_isupper
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int check = 0;

    while (str[i] != '\0') {
        check = str[i] >= 65 && str[i] <= 90;
        if (!check)
            return (0);
        i++;
    }
    return (1);
}
