/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** utils_particles.c
*/

#include "rpg.h"
#include <math.h>

float gen_random_in_range(float lower, float upper)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = upper - lower;
    float r = random * diff;
    return lower + r;
}

static float calc_norm_vector(sfVector2f vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

sfVector2f calc_vector(sfVector2f point1, sfVector2f point2)
{
    sfVector2f vector;
    vector.x = point2.x - point1.x;
    vector.y = point2.y - point1.y;
    float norm = calc_norm_vector(vector);
    vector.x /= norm + 1;
    vector.y /= norm + 1;
    return vector;
}
