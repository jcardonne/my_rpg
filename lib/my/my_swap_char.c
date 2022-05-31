/*
** EPITECH PROJECT, 2021
** MY_SWAP_CHAR
** File description:
** Swap two char
*/

int my_swap_char(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
    return (0);
}
