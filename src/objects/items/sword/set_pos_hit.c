/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** set_pos_hit.c
*/

#include "rpg.h"

item_t *get_selected_item(game_t *game);

void set_pos_hit(game_t *game, sfVector2f pos)
{
    item_t *item = get_selected_item(game);
    pos.x -= 5;
    pos.y -= 5;
    sfSprite_setPosition(item->sprite_effect, pos);
}
