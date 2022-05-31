/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** entity
*/

#include "rpg.h"

entity_t *init_entity(option_t option)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(option.path, NULL);
    entity->spritesheet_width = option.spritesheet_width;
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setScale(entity->sprite, option.scale);
    sfSprite_setPosition(entity->sprite, option.pos);
    if (option.int_rect.width != -1) {
        entity->rect = option.int_rect;
        sfSprite_setTextureRect(entity->sprite, option.int_rect);
    }
    if (option.rotation != 0)
        sfSprite_setRotation(entity->sprite, option.rotation);
    entity->spritesheet_rect_x = option.rect_x;
    entity->spritesheet_rect_y = option.rect_y;
    return (entity);
}
