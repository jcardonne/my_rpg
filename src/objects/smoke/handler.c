/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler.c
*/

#include "rpg.h"
#include "object.h"

void handler_smoke(game_t *game, struct object_s *self)
{
    smoke_t *smoke = self->data;
    static long last_clock = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock) / 1000000.0;
    if (diff >= 0.15) {
        smoke->offset_x += 16;
        if (smoke->offset_x >= 100) {
            smoke->offset_x = 0;
            smoke->offset_pos_x = 0;
            smoke->offset_pos_y = 0;
        }
        last_clock = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    smoke->offset_pos_x += 0.3;
    smoke->offset_pos_y += 0.3;
    sfVector2f new_pos = {smoke->pos.x + smoke->offset_pos_x,
                            smoke->pos.y - smoke->offset_pos_y};
    sfSprite_setPosition(smoke->sprite, new_pos);
    sfSprite_setTextureRect(smoke->sprite,
                            (sfIntRect){smoke->offset_x, 0, 16, 23});
}
