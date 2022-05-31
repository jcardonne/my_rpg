/*
** EPITECH PROJECT, 2021
** power.c
** File description:
** power
*/

int power(int nb, int power)
{
    int result = 1;

    for (int i = 0 ; i < power ; i++)
        result *= nb;
    return (result);
}
