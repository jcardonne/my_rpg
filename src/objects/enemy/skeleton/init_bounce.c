/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init_bounce.c
*/

#include "rpg.h"

sfVector2i create_translation(sfVector2f pos);
sfVector2f get_destination_3d(game_t *game, enemy_t *enemy);

void init_bounce(enemy_t *skeleton, game_t *game)
{
    skeleton->translation = create_translation(skeleton->self_pos);
    skeleton->direction_3d = get_destination_3d(game, skeleton);
    skeleton->bouncing = 1;
    skeleton->coords_3d.x = skeleton->self_pos.x;
    skeleton->coords_3d.y = skeleton->self_pos.y;
    skeleton->coords_3d.z = 0;
    skeleton->direction_3d.x *= -1;
    skeleton->direction_3d.y *= -1;
}
