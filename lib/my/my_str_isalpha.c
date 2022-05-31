/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int check = 0;
    char temp;

    while (str[i] != '\0') {
        temp = str[i];
        check = (temp >= 97 && temp <= 122) || (temp >= 65 && temp <= 90);
        if (!check)
            return (0);
        i++;
    }
    return (1);
}
