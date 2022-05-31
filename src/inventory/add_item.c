/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** add_item.c
*/

#include "rpg.h"

void add_item(game_t *game, object_t *item)
{
    player_t *player = CAST_PLAYER(game->play->player->data);

    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (player->inventory.items[i] == NULL) {
            player->inventory.items[i] = item;
            return;
        }
    }
}

void add_item_on_id(game_t *game, object_t *item, int pos)
{
    player_t *player = CAST_PLAYER(game->play->player->data);

    if (player->inventory.items[pos] == NULL)
        player->inventory.items[pos] = item;
}
