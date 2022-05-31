/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"
#include "object.h"

void draw_smoke(game_t *game, struct object_s *self)
{
    smoke_t *smoke = self->data;
    sfRenderWindow_drawSprite(game->window, smoke->sprite, NULL);
}
