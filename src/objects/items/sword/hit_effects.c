/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** hit_effects.c
*/

#include "rpg.h"

void handle_display(game_t *game, item_t *sword, double diff)
{
    if (diff <= 0.1) {
        sfSprite_setTextureRect(sword->sprite_effect,
                                (sfIntRect){0, 0, 16, 16});
        sfRenderWindow_drawSprite(game->window, sword->sprite_effect, NULL);
    } else if (diff <= 0.2) {
        sfSprite_setTextureRect(sword->sprite_effect,
                                (sfIntRect){16, 0, 16, 16});
        sfRenderWindow_drawSprite(game->window, sword->sprite_effect, NULL);
    } else {
        sfSprite_setTextureRect(sword->sprite_effect,
                                (sfIntRect){0, 0, 16, 16});
        sword->hit_effect = 0;
    }
}

void sword_hit_effect(game_t *game, item_t *sword)
{
    sfTexture *texture = NULL;
    static long last_hit_effect = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_hit_effect) / 1000000.0;
    if (texture == NULL) {
        texture = sfTexture_createFromFile(
                                "assets/spritesheets/hit_effects.png", NULL);
        sfSprite_setTexture(sword->sprite_effect, texture, sfFalse);
        sfSprite_setScale(sword->sprite_effect, (sfVector2f){0.5, 0.5});
    }
    if (sword->hit_effect)
        handle_display(game, sword, diff);
    else
        last_hit_effect = current_us;
}
