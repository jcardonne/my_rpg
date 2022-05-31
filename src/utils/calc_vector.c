/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** calc_vector.c
*/

#include "rpg.h"
#include <math.h>

sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2)
{
    return (sfVector2f){point2.x - point1.x, point2.y - point1.y};
}