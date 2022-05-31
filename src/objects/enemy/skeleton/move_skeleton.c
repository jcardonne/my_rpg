/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** animate_skeleton.c
*/

#include "rpg.h"
#include "object.h"

float calc_distance(sfVector2f point1, sfVector2f point2);
void change_direction(enemy_t *enemy, sfVector2f new_destination);
int in_range_player(game_t *game, enemy_t *enemy);
int check_collision(game_t *game, entity_t entity, sfVector2f shift, int dead);
void reset_jump_state(game_t *game, enemy_t *enemy);
void handle_jump(game_t *game, enemy_t *enemy);
sfVector2f get_destination_3d(game_t *game, enemy_t *enemy);
sfVector2f get_pos_player(game_t *game);
sfVector2i create_translation(sfVector2f pos);
void init_bounce(enemy_t *skeleton, game_t *game);

static void handle_idle_state(game_t *game, enemy_t *skeleton)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us -
                    skeleton->animation_data.last_idle_state) / 1000000.0;
    if (in_range_player(game, skeleton)) {
        sfVector2f pos_player = get_pos_player(game);
        skeleton->animation_data.animation_state = MOVING;
        skeleton->trigerred = 1;
        change_direction(skeleton, pos_player);
        return;
    }
    if (diff >= 4) {
        skeleton->animation_data.animation_state = MOVING;
        skeleton->animation_data.last_idle_state = current_us;
    }
}

static void handle_movement_animation(game_t *game, enemy_t *skeleton)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us -
                    skeleton->animation_data.last_move_animation) / 1000000.0;
    if (diff >= 0.1) {
        skeleton->offset_x += skeleton->entity.spritesheet_rect_x;
        sfSprite_setTextureRect(skeleton->entity.sprite,
            (sfIntRect){skeleton->offset_x, skeleton->offset_y,
            skeleton->entity.spritesheet_rect_x,
            skeleton->entity.spritesheet_rect_y});
        if (skeleton->offset_x >= skeleton->entity.spritesheet_width -
            skeleton->entity.spritesheet_rect_x)
            skeleton->offset_x = 0;
        skeleton->animation_data.last_move_animation = current_us;
    }
}

static void handle_direction(game_t *game, enemy_t *skeleton)
{
    skeleton->self_pos.x += skeleton->direction.x;
    skeleton->self_pos.y += skeleton->direction.y;
    if (in_range_player(game, skeleton)) {
        sfVector2f pos_player = get_pos_player(game);
        skeleton->trigerred = 1;
        change_direction(skeleton, pos_player);
        return;
    }
    float distance = calc_distance(skeleton->self_pos,
                    skeleton->pos[skeleton->where_to_go]);
    if (skeleton->trigerred) {
        change_direction(skeleton, skeleton->pos[skeleton->where_to_go]);
        skeleton->trigerred = 0;
    } else if (distance <= 5) {
        skeleton->where_to_go = (skeleton->where_to_go == 0) ? 1 : 0;
        change_direction(skeleton, skeleton->pos[skeleton->where_to_go]);
    }
}

static void handle_bounce(game_t *game, enemy_t *skeleton)
{
    skeleton->animation_data.distance_jumped += 1;
    if (skeleton->animation_data.distance_jumped >=
                                        skeleton->animation_data.jump_height) {
        reset_jump_state(game, skeleton);
    } else {
        handle_jump(game, skeleton);
    }
}

void move_skeleton(game_t *game, enemy_t *skeleton)
{
    skeleton->animation_data.jump_height = 20;
    if (skeleton->animation_data.animation_state == STATIC)
        handle_idle_state(game, skeleton);
    else {
        if (!skeleton->bouncing)
            handle_movement_animation(game, skeleton);
        if (check_collision(game, skeleton->entity, skeleton->direction,
            skeleton->animation_data.animate_death) && !skeleton->bouncing)
            init_bounce(skeleton, game);
        if (!skeleton->bouncing) {
            handle_direction(game, skeleton);
            sfSprite_move(skeleton->entity.sprite,
                (sfVector2f){skeleton->direction.x, skeleton->direction.y});
        } else
            handle_bounce(game, skeleton);
    }
}
