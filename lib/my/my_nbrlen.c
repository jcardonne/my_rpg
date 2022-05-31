/*
** EPITECH PROJECT, 2021
** nbrlen
** File description:
** my_nbrlen
*/

int my_compute_power_rec(int nb, int p);

int my_nbrlen(int number)
{
    int i = 1;
    int temp = number;

    for (; temp > 0; i++)
        if (temp / my_compute_power_rec(10, i) <= 0)
            break;
    return (i);
}
