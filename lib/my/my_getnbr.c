/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** String -> Int
*/

static int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static int my_getnbr_two(char const * str, long n, int neg, int i)
{
    return str[i + 1] != '\0' && str[i + 1] >= '0' && str[i + 1] <= '9';
}

int my_getnbr(char const *str)
{
    long n = 0;
    int neg = 0;
    int conditions = 0;

    if (str[0] != '-' && is_digit(str[0]) == 0)
        return -1;
    for (int i = 0; str[i]; i++) {
        str[i] == '-' ? neg++ : neg;
        if (str[i] >= '0' && str[i] <= '9') {
            n += (str[i] - '0');
            my_getnbr_two(str, n, neg, i) ? n *= 10 : n;
        } else if (str[i] != '-') {
            break;
        }
        if (str[i + 1] < '0' || str[i + 1] > '9') {
            n = neg % 2 != 0 ? (-1 * n) : n;
            n < -2147483648 || n > 2147483647 ? n = 0 : n;
            return (n);
        }
    }
    return (n);
}
