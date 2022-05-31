/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"
#include "object.h"

void draw_border_wave(game_t *game, object_t *self)
{
    waves_border_t *border = self->data;
    sfRenderWindow_drawSprite(game->window, border->sprite, NULL);
}
