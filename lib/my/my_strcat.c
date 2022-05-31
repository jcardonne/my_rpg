/*
** EPITECH PROJECT, 2022
** MY_STRCAT
** File description:
** Concatenates two strings.
*/

int my_char_isprintable(char const str);
int my_strlen(char const * str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int index = 0;

    while (index < my_strlen(src))
        dest[i++] = src[index++];
    dest[i] = '\0';
    return (dest);
}
