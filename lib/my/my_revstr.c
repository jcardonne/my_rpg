/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Reverse a string
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int ln = my_strlen(str);
    char temp;

    for (int i = 0; i < ln / 2; i++) {
        temp = str[i];
        str[i] = str[ln - i - 1];
        str[ln - i - 1] = temp;
    }
    return (str);
}
