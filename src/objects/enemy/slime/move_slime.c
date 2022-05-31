/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** move_slime.c
*/

#include "rpg.h"
#include "object.h"

int in_range_player(game_t *game, enemy_t *enemy);
void change_direction(enemy_t *enemy, sfVector2f new_destination);
float calc_distance(sfVector2f point1, sfVector2f point2);
void slime_jump(game_t *game, enemy_t *slime);
sfVector2f get_pos_player(game_t *game);
void reset_jump_state(game_t *game, enemy_t *enemy);
void play_sound(game_t *game, sfSound *sound);

static void handle_idle_state(game_t *game, enemy_t *slime)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us -
                    slime->animation_data.last_idle_state) / 1000000.0;
    if (in_range_player(game, slime)) {
        sfVector2f pos_player = get_pos_player(game);
        slime->animation_data.animation_state = MOVING;
        slime->trigerred = 1;
        change_direction(slime, pos_player);
        return;
    }
    if (diff >= 1.5) {
        slime->animation_data.animation_state = MOVING;
        slime->animation_data.last_idle_state = current_us;
    }
}

static void handle_direction(game_t *game, enemy_t *slime)
{
    if (in_range_player(game, slime)) {
        sfVector2f pos_player = get_pos_player(game);
        slime->trigerred = 1;
        change_direction(slime, pos_player);
        return;
    }
    float distance = calc_distance(slime->self_pos,
                    slime->pos[slime->where_to_go]);
    if (slime->trigerred) {
        change_direction(slime, slime->pos[slime->where_to_go]);
        slime->trigerred = 0;
    } else if (distance <= 10) {
        slime->where_to_go = (slime->where_to_go == 0) ? 1 : 0;
        change_direction(slime, slime->pos[slime->where_to_go]);
    }
}

static void handle_movement_animation(game_t *game, enemy_t *slime)
{
    if (slime->animation_data.animation_state == JUMPING)
        return;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us -
                    slime->animation_data.last_move_animation) / 1000000.0;
    if (diff >= 1) {
        slime->offset_x += slime->entity.spritesheet_rect_x;
        if (slime->offset_x >= slime->entity.spritesheet_width -
                                slime->entity.spritesheet_rect_x) {
            slime->animation_data.animation_state = JUMPING;
            play_sound(game, game->audio.jump);
        }
        sfSprite_setTextureRect(slime->entity.sprite,
            (sfIntRect){slime->offset_x, slime->offset_y,
            slime->entity.spritesheet_rect_x,
            slime->entity.spritesheet_rect_y});
        slime->animation_data.last_move_animation = current_us;
    }
}

static void handle_jump_slime(game_t *game, enemy_t *slime)
{
    slime->animation_data.distance_jumped += 1;
    if (slime->animation_data.distance_jumped >=
        slime->animation_data.jump_height) {
        reset_jump_state(game, slime);
    } else
        slime_jump(game, slime);
}

void move_slime(game_t *game, enemy_t *slime)
{
    if (slime->animation_data.animation_state == STATIC) {
        handle_idle_state(game, slime);
        handle_direction(game, slime);
    } else if (slime->animation_data.animation_state == JUMPING) {
        handle_jump_slime(game, slime);
        handle_direction(game, slime);
    } else
        handle_movement_animation(game, slime);
}
