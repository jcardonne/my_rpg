/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** in_range_player.c
*/

#include "rpg.h"
#include "object.h"

float calc_distance(sfVector2f point1, sfVector2f point2);

int in_range_player(game_t *game, enemy_t *enemy)
{
    sfVector2f pos_player =
        sfSprite_getPosition
        (CAST_PLAYER(game->play->player->data)->entity.sprite);
    float distance = calc_distance(pos_player, enemy->self_pos);
    if (enemy->trigerred)
        distance /= 3;
    if (distance <= enemy->stats.range_aggro)
        return 1;
    return 0;
}
