/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"

int is_equipped(game_t *game, int id);

void draw_item(game_t *game, object_t *self)
{
    item_t *item = self->data;
    if (!item->on_the_ground || is_equipped(game, item->id))
        return;
    sfRenderWindow_drawSprite(game->window, item->entity->sprite, NULL);
}
