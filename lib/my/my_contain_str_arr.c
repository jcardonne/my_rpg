/*
** EPITECH PROJECT, 2021
** my_contain_str_arr
** File description:
** my_contain_str_arr
*/

int my_strcmp(char const *s1, char const *s2);
int my_arr_size(char **arr);

int my_contain_str_arr(char **arr, char *to_find)
{
    for (int i = 0; i < my_arr_size(arr); i++)
        if (my_strcmp(arr[i], to_find) == 0)
            return (1);
    return (0);
}
