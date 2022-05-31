/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** time
*/

#include "rpg.h"

my_time_t *init_clock(void)
{
    my_time_t *clock = malloc(sizeof(my_time_t));

    clock->clock = sfClock_create();
    clock->seconds = 0;
    return (clock);
}
