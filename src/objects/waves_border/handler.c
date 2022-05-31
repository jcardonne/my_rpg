/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler.c
*/

#include "rpg.h"
#include "object.h"

void handler_border_wave(game_t *game, object_t *self)
{
    waves_border_t *border = self->data;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - border->last_clock) / 1000000.0;
    if (diff >= 1) {
        border->offset_x += 48 * border->direction;
        if (border->offset_x >= 96 || border->offset_x <= 16)
            border->direction *= -1;
        border->last_clock =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    sfSprite_setTextureRect(border->sprite,
                    (sfIntRect){border->offset_x, border->offset_y, 16, 16});
}
