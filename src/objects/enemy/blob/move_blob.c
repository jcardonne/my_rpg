/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** move_blob.c
*/

#include "rpg.h"
#include "object.h"

int in_range_player(game_t *game, enemy_t *enemy);
void change_direction(enemy_t *enemy, sfVector2f new_destination);
float calc_distance(sfVector2f point1, sfVector2f point2);
void blob_jump(game_t *game, enemy_t *blob);
sfVector2f get_pos_player(game_t *game);
void reset_jump_state(game_t *game, enemy_t *enemy);
void play_sound(game_t *game, sfSound *sound);

static void handle_idle_state(game_t *game, enemy_t *blob)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us -
                    blob->animation_data.last_idle_state) / 1000000.0;
    if (diff >= 1.5) {
        blob->animation_data.animation_state = MOVING;
        blob->animation_data.last_idle_state = current_us;
    }
}

static void handle_direction(game_t *game, enemy_t *blob)
{
    sfVector2f pos_player = get_pos_player(game);
    blob->trigerred = 1;
    change_direction(blob, pos_player);
}

static void handle_movement_animation(game_t *game, enemy_t *blob)
{
    if (blob->animation_data.animation_state == JUMPING)
        return;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us -
                    blob->animation_data.last_move_animation) / 1000000.0;
    if (diff >= 1) {
        blob->offset_x += blob->entity.spritesheet_rect_x;
        if (blob->offset_x >= blob->entity.spritesheet_width -
                                blob->entity.spritesheet_rect_x) {
            blob->animation_data.animation_state = JUMPING;
            play_sound(game, game->audio.jump);
        }
        sfSprite_setTextureRect(blob->entity.sprite,
            (sfIntRect){blob->offset_x, blob->offset_y,
            blob->entity.spritesheet_rect_x,
            blob->entity.spritesheet_rect_y});
        blob->animation_data.last_move_animation = current_us;
    }
}

static void handle_jump_blob(game_t *game, enemy_t *blob)
{
    blob->animation_data.distance_jumped += 1;
    if (blob->animation_data.distance_jumped >=
        blob->animation_data.jump_height) {
        reset_jump_state(game, blob);
    } else
        blob_jump(game, blob);
}

void move_blob(game_t *game, enemy_t *blob)
{
    blob->animation_data.jump_height = 40;
    if (blob->animation_data.animation_state == STATIC) {
        handle_idle_state(game, blob);
        handle_direction(game, blob);
    } else if (blob->animation_data.animation_state == JUMPING) {
        handle_jump_blob(game, blob);
        handle_direction(game, blob);
    } else
        handle_movement_animation(game, blob);
}
