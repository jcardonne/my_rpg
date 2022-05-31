/*
** EPITECH PROJECT, 2021
** my_sort_str_array
** File description:
** my_sort_str_array
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2);
int my_arr_size(char **arr);

void my_sort_str_array_two(char **array, int size_of_array, int i)
{
    char *temp = NULL;

    for (int j = 0; j < size_of_array - i; j++) {
        if (my_strcmp(array[j], array[j + 1]) > 0) {
            temp = malloc(sizeof(char) * 1000000);
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }
}

void my_sort_str_array(char **array)
{
    int size_of_array = my_arr_size(array) - 1;

    for (int i = 0; i < size_of_array + 1; i++) {
        my_sort_str_array_two(array, size_of_array, i);
    }
}
