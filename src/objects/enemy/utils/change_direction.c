/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** change_direction.c
*/

#include "rpg.h"
#include "object.h"

sfVector2f normalize_vector(sfVector2f vector);
sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2);

void set_sprite_orientation(enemy_t *enemy)
{
    if (enemy->direction.x > 0)
        enemy->offset_y = 0;
    else
        enemy->offset_y = enemy->entity.spritesheet_rect_y;
    sfSprite_setTextureRect(enemy->entity.sprite,
                        (sfIntRect){enemy->offset_x, enemy->offset_y,
                        enemy->entity.spritesheet_rect_x,
                        enemy->entity.spritesheet_rect_y});
}

void change_direction(enemy_t *enemy, sfVector2f new_destination)
{
    enemy->direction =
    normalize_vector(calc_new_vector(enemy->self_pos, new_destination));
    if (!enemy->trigerred) {
        enemy->animation_data.animation_state = 0;
        enemy->offset_x = 0;
    }
    set_sprite_orientation(enemy);
}
