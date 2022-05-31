/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void change_region(game_t *game, region_t *current_region,
int dir_x, int dir_y);
int is_equipped(game_t *game, int id);

void teleporter_handler(game_t *game, struct object_s *self)
{
    teleporter_t *teleporter = self->data;
    sfFloatRect rect = sfSprite_getGlobalBounds(
        ((player_t *)(game->play->player->data))->entity.sprite);

    if (sfFloatRect_intersects(&rect, &teleporter->area, NULL))
        change_region(game, teleporter->dest_region, 0, 0);
}

void dungeon_teleporter_handler(game_t *game, struct object_s *self)
{
    teleporter_t *teleporter = self->data;
    sfFloatRect rect = sfSprite_getGlobalBounds(
        ((player_t *)(game->play->player->data))->entity.sprite);

    if (sfFloatRect_intersects(&rect, &teleporter->area, NULL)
        && is_equipped(game, KEY))
        change_region(game, teleporter->dest_region, 0, 0);
}
