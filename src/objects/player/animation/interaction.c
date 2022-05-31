/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** interaction.c
*/

#include "rpg.h"

void rect_animation_interaction(game_t *game, entity_t *entity)
{
    if (entity->rect.left >= entity->spritesheet_width -
        entity->spritesheet_rect_x) {
        entity->rect.left = 0;
        CAST_PLAYER(game->play->player->data)->entity.animation_state
            = IDLE_STATE;
    }
    entity->rect.left = entity->spritesheet_width - entity->spritesheet_rect_x;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void interact_player(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
            = INTERACTION_STATE;
    if (diff >= 0.2) {
        rect_animation_interaction(game,
                    &((player_t *)(game->play->player->data))->entity);
        last_clock_us = sfClock_getElapsedTime(
            game->clock->clock).microseconds;
    }
}
