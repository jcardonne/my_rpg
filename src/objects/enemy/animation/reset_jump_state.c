/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** reset_jump_state.c
*/

#include "rpg.h"
#include "object.h"

int in_range_player(game_t *game, enemy_t *enemy);
void change_direction(enemy_t *enemy, sfVector2f new_destination);
sfVector2f get_pos_player(game_t *game);

void reset_jump_state(game_t *game, enemy_t *enemy)
{
    enemy->bouncing = 0;
    enemy->animation_data.animation_state = STATIC;
    enemy->coords_3d.z = 0;
    enemy->offset_x = 0;
    enemy->animation_data.distance_jumped = 0;
    enemy->animation_data.last_move_animation =
                sfClock_getElapsedTime(game->clock->clock).microseconds;
    sfSprite_setTextureRect(enemy->entity.sprite,
        (sfIntRect){enemy->offset_x, enemy->offset_y,
        enemy->entity.spritesheet_rect_x,
        enemy->entity.spritesheet_rect_y});
    if (in_range_player(game, enemy) || enemy->id == BLOB) {
        sfVector2f pos_player = get_pos_player(game);
        enemy->animation_data.animation_state = MOVING;
        enemy->trigerred = 1;
        change_direction(enemy, pos_player);
    } else
        change_direction(enemy, enemy->pos[enemy->where_to_go]);
}
