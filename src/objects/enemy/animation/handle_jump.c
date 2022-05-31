/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handle_jump.c
*/

#include "rpg.h"
#include "object.h"
#include <math.h>

sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2);
sfVector2f normalize_vector(sfVector2f vector);
sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate);

void handle_jump(game_t *game, enemy_t *enemy)
{
    enemy->self_pos = project_iso_point(enemy->coords_3d, enemy->translation);
    if (enemy->animation_data.distance_jumped <
                                        enemy->animation_data.jump_height / 2)
        enemy->coords_3d.z++;
    else
        enemy->coords_3d.z--;
    enemy->coords_3d.x += enemy->direction_3d.x;
    enemy->coords_3d.y += enemy->direction_3d.y;
    sfSprite_setPosition(enemy->entity.sprite, enemy->self_pos);
    sfRenderWindow_drawSprite(game->window, enemy->entity.sprite, NULL);
}
