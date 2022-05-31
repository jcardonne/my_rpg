/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler.c
*/

#include "rpg.h"

void handler_grass(game_t *game, object_t *self)
{
    grass_t *grass = self->data;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - grass->last_animation) / 1000000.0;
    if (grass->is_hit) {
        if (diff >= 0.15) {
            grass->offset_x += 23;
            grass->last_animation = current_us;
            grass->pos.x -= 7;
            grass->pos.y -= 5;
            sfSprite_setPosition(grass->sprite, grass->pos);
        }
        if (grass->offset_x >= 30)
            grass->destroyed = 1;
    } else {
        grass->last_animation = current_us;
    }
}
