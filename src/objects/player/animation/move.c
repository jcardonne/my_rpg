/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** move.c
*/

#include "rpg.h"

void set_player_animation_settings(game_t *game, int status);

void rect_set_y(game_t *game, int status)
{
    entity_t *entity = &CAST_PLAYER(game->play->player->data)->entity;

    set_player_animation_settings(game, status);
    if (entity->spritesheet_rect_y != 0)
        entity->rect.top = entity->spritesheet_rect_y * status;
    if (entity->rect.top >= entity->spritesheet_height)
        entity->rect.top = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_movement(entity_t *entity)
{
    if (entity->rect.left < 32)
        entity->rect.left = 32;
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= entity->spritesheet_width)
        entity->rect.left = 32;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_idle(entity_t *entity)
{
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= 32)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}
