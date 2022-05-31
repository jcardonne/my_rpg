/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** get_pos_player.c
*/

#include "rpg.h"

sfVector2f get_pos_player(game_t *game)
{
    return sfSprite_getPosition(
                        CAST_PLAYER(game->play->player->data)->entity.sprite);
}