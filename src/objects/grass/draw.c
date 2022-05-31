/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"

void draw_grass(game_t *game, object_t *self)
{
    grass_t *grass = self->data;
    if (grass->destroyed)
        return;
    sfSprite_setScale(grass->sprite, (sfVector2f){1, 1});
    sfSprite_setTextureRect(grass->sprite,
                    (sfIntRect){grass->offset_x, 0, 23, 15});
    sfRenderWindow_drawSprite(game->window, grass->sprite, NULL);
}
