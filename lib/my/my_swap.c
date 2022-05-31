/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swap two variable
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
