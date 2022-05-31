/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(char const * str);
int my_char_isprintable(char const str);

char *my_strncat(char *dest , char const *src, int nb)
{
    int index = 0;
    int dest_ln = my_strlen(dest);
    int src_ln = my_strlen(src);

    for (int i = dest_ln; i < dest_ln + src_ln; i++) {
        if (index == nb)
            return (dest);
        if (my_char_isprintable(src[index]) == 1 && i == my_strlen(dest)) {
            dest[i] = src[index];
            index++;
        }
    }
    return (dest);
}
