/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** Find the sup prime of the number's given
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int ok = 0;
    int temp = nb;

    if (my_is_prime(nb) == 1)
        return (nb);

    while (ok == 0) {
        if (my_is_prime(temp) == 1) {
            return (temp);
        }
        temp++;
    }

    return (0);
}
