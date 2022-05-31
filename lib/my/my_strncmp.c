/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

int my_strlen(char const * str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_point = 0;
    int s2_point = 0;
    int diff = 0;

    if (n <= 0)
        return (0);

    for (int i = 0; i < my_strlen(s1); i++) {
        s1_point += s1[i];
        s2_point += s2[i];
        if (i == n - 1)
            break;
        if (s1_point == s2_point && i == my_strlen(s1) - 1)
            return (0);
    }
    diff = s1_point - s2_point;
    return diff;
}
