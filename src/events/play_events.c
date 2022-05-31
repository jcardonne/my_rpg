/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include <stdio.h>

void rect_animation_movement(entity_t *entity);
void rect_animation_idle(entity_t *entity);
void interact_player(game_t *game);

void player_idle_animation(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = IDLE_STATE;
    if (diff >= 0.5) {
        rect_animation_idle(&(CAST_PLAYER(game->play->player->data)->entity));
        last_clock_us =
                sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void player_movement_animation(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = MOVEMENT_STATE;
    if (diff >= 0.2) {
        rect_animation_movement(&((player_t *)
                                (game->play->player->data))->entity);
        last_clock_us =
                sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}
