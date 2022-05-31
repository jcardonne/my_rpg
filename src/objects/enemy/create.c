/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create
*/

#include "rpg.h"
#include "object.h"
#include "region.h"

sfVector2f normalize_vector(sfVector2f vector);
sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2);
sfVector2i create_translation(sfVector2f pos);

static void init_enemy_entity(enemy_t *enemy, option_t option)
{
    enemy->entity.texture = sfTexture_createFromFile(option.path, NULL);
    enemy->entity.sprite = sfSprite_create();
    enemy->entity.spritesheet_width = option.spritesheet_width;
    enemy->entity.spritesheet_height = option.spritesheet_height;
    sfSprite_setTexture(enemy->entity.sprite, enemy->entity.texture, sfTrue);
    sfSprite_setScale(enemy->entity.sprite, option.scale);
    sfSprite_setOrigin(enemy->entity.sprite, (sfVector2f){option.rect_x / 2,
        option.rect_y / 2});
    sfSprite_setPosition(enemy->entity.sprite, enemy->pos[0]);
    enemy->entity.rect = option.int_rect;
    sfSprite_setTextureRect(enemy->entity.sprite, option.int_rect);
    enemy->entity.spritesheet_rect_x = option.rect_x;
    enemy->entity.spritesheet_rect_y = option.rect_y;
}

static void init_animation(enemy_t *enemy)
{
    enemy->animation_data.breath_state = 1;
    enemy->animation_data.last_breath_out_animation = 0;
    enemy->animation_data.last_breathing_animation = 0;
    enemy->animation_data.last_move_animation = 0;
    enemy->animation_data.last_idle_state = 0;
    enemy->animation_data.distance_jumped = 0;
    enemy->animation_data.jump_height = 30;
    enemy->animation_data.distance_jumped = 0;
    enemy->animation_data.animation_state = STATIC;
    enemy->bouncing = 0;
    enemy->animation_data.animate_death = 0;
    enemy->animation_data.last_death_animation = 0;
    enemy->dead = 0;
}

static void init_coords(sfVector2f *pos, enemy_t *enemy)
{
    enemy->self_pos = pos[0];
    enemy->coords_3d.x = pos[0].x;
    enemy->coords_3d.y = pos[0].y;
    enemy->coords_3d.z = 0;
    enemy->pos = pos;
    enemy->where_to_go = 1;
}

enemy_t *create_enemy(sfVector2f *pos, option_t option, stats_t stats)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    init_coords(pos, enemy);
    init_enemy_entity(enemy, option);
    enemy->direction =
        normalize_vector(calc_new_vector(enemy->self_pos, enemy->pos[1]));
    enemy->direction_3d.x = enemy->direction.x;
    enemy->direction_3d.y = enemy->direction.y;
    init_animation(enemy);
    enemy->stats = stats;
    enemy->offset_x = 0;
    enemy->offset_y = 0;
    enemy->trigerred = 0;
    enemy->invincibility = 0;
    enemy->emitters = NULL;
    enemy->is_hit = 0;
    enemy->translation = create_translation(pos[0]);
    return enemy;
}
