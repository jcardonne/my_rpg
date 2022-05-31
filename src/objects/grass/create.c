/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create.c
*/

#include "rpg.h"

grass_t *create_grass(sfVector2f pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x > 1920 || pos.y > 1080)
        return NULL;
    grass_t *grass = malloc(sizeof(grass_t));
    grass->pos = pos;
    static sfTexture *texture = NULL;
    if (texture == NULL)
        texture = sfTexture_createFromFile("assets/spritesheets/grass.png",
                                            NULL);
    grass->sprite = sfSprite_create();
    sfSprite_setTexture(grass->sprite, texture, sfFalse);
    sfSprite_setPosition(grass->sprite, grass->pos);
    grass->offset_x = 0;
    grass->last_animation = 0;
    grass->destroyed = 0;
    grass->is_hit = 0;
    return grass;
}
