/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** calc_dist.c
*/

#include <math.h>
#include "rpg.h"

float calc_distance(sfVector2f point1, sfVector2f point2)
{
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}
