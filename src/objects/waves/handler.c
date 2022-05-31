/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler.c
*/

#include "rpg.h"
#include "object.h"

void handler_wave(game_t *game, struct object_s *self)
{
    waves_t *wave = self->data;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - wave->last_clock) / 1000000.0;
    if (diff >= 0.5) {
        wave->offset_x += 16;
        if (wave->offset_x >= 96)
            wave->offset_x = 0;
        wave->last_clock =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    sfSprite_setTextureRect(wave->sprite,
        (sfIntRect){wave->offset_x, 0, 16, 16});
}