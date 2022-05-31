/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** stats_enemy
*/

#include "object.h"

stats_t blob_stats(void)
{
    stats_t stats;

    stats.damage = 1;
    stats.life_points = 18;
    stats.range_aggro = 10;
    stats.speed = 1;
    return stats;
}

stats_t slime_stats(void)
{
    stats_t stats;

    stats.damage = 1;
    stats.life_points = 6;
    stats.range_aggro = 50;
    stats.speed = 1;
    return stats;
}

stats_t ghost_stats(void)
{
    stats_t stats;

    stats.damage = 2;
    stats.life_points = 1;
    stats.range_aggro = 10;
    stats.speed = 1;
    return stats;
}

stats_t skeleton_stats(void)
{
    stats_t stats;

    stats.damage = 3;
    stats.life_points = 9;
    stats.range_aggro = 50;
    stats.speed = 1;
    return stats;
}
