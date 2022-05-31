/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** getter.c
*/

#include "rpg.h"
#include "my.h"

const static option_t option[NB_ITEMS] = {
    { "./assets/spritesheets/items.png", (sfVector2f) {2, 2},
    (sfVector2f) {69.5, 488.0}, (sfIntRect) {2, 16, 10, 16}, 15.6666666667,
    17.6666666667, 47, 53, 90.0, "Sword" },
    {"./assets/spritesheets/items.png", (sfVector2f) {1, 1},
    (sfVector2f){-1, -1}, (sfIntRect){0, 0, 10, 12},  0, 0, 0, 0, 0, "Key"},
};

option_t get_option_by_id(int id)
{
    return option[id];
}

item_t *get_selected_item(game_t *game)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t inventory = player->inventory;

    if (inventory.items[0] == NULL)
        return NULL;
    else
        return ((item_t *)(inventory.items[0]->data));
}

int is_equipped(game_t *game, int id)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t inventory = player->inventory;

    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (inventory.items[i] == NULL)
            continue;
        else if (((item_t *)(inventory.items[i]->data))->id == id)
            return 1;
    }
    return 0;
}
