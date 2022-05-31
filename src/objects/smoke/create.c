/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create.c
*/

#include "rpg.h"
#include "object.h"

smoke_t *create_smoke(game_t *game, sfVector2f pos)
{
    if (pos.x < 0 || pos.y < 0)
        return NULL;
    smoke_t *smoke = malloc(sizeof(smoke_t));
    smoke->pos = pos;
    static sfTexture *texture = NULL;
    if (texture == NULL) {
        texture =
            sfTexture_createFromFile("assets/spritesheets/smoke.png", NULL);
    }
    smoke->sprite = sfSprite_create();
    sfSprite_setTexture(smoke->sprite, texture, sfFalse);
    sfSprite_setScale(smoke->sprite, (sfVector2f){1, 1});
    smoke->offset_x = 0;
    smoke->offset_pos_x = 0;
    smoke->offset_pos_y = 0;
    return smoke;
}
