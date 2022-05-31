/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void move_skeleton(game_t *game, enemy_t *enemy);
void move_slime(game_t *game, enemy_t *slime);
void move_blob(game_t *game, enemy_t *blob);
void move_ghost(game_t *game, enemy_t *ghost);
void set_end_blob_scene(game_t *game);

static void (*move[4])(game_t *, enemy_t *) = {
    &move_blob,
    &move_slime,
    &move_skeleton
};

static void handle_enemy_combat(game_t *game, enemy_t *enemy)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - enemy->invincibility) / 1000000.0;
    if (enemy->is_hit) {
        if (diff >= 0.5) {
            enemy->is_hit = 0;
            sfSprite_setColor(enemy->entity.sprite, sfWhite);
            enemy->invincibility = 0;
        } else {
            sfColor color_hit = {250, 100, 100, 255};
            sfSprite_setColor(enemy->entity.sprite, color_hit);
        }
    } else
        enemy->invincibility = current_us;
}

static void animation_enemy_breathing(game_t *game, enemy_t *enemy)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    static int multiplier = 1;
    sfVector2f scale = sfSprite_getScale(enemy->entity.sprite);
    animation_data_t data = enemy->animation_data;

    if ((current_us - data.last_breathing_animation) / 1000000.0 >= 0.3) {
        scale.x += 0.03 * data.breath_state;
        scale.y += 0.01 * data.breath_state;
        sfSprite_setScale(enemy->entity.sprite, scale);
        data.last_breathing_animation =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    if ((current_us - data.last_breath_out_animation) / 1000000.0 >= 1) {
        data.breath_state = data.breath_state == 1 ? -1 : 1;
        data.last_breath_out_animation =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    enemy->animation_data = data;
}

static void handle_death_animation(game_t *game, enemy_t *enemy)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    if (!enemy->animation_data.animate_death) {
        enemy->animation_data.last_death_animation = current_us;
        return;
    }
    double diff = (current_us - enemy->animation_data.last_death_animation) /
                    1000000.0;
    if (diff >= 0.1) {
        enemy->entity.spritesheet_rect_x += 29;
        if (enemy->entity.spritesheet_rect_x >= 145) {
            enemy->dead = 1;
            return;
        }
        sfSprite_setTextureRect(enemy->entity.sprite,
                    (sfIntRect){enemy->entity.spritesheet_rect_x, 0, 29, 18});
        enemy->animation_data.last_death_animation = current_us;
    }
}

static void init_death_state(enemy_t *enemy, game_t *game)
{
    if (enemy->id == BLOB) {
        set_end_blob_scene(game);
        return;
    }
    enemy->entity.spritesheet_rect_x = 0;
    enemy->entity.spritesheet_rect_y = 0;
    enemy->entity.spritesheet_width = 29;
    enemy->entity.spritesheet_height = 18;
    enemy->animation_data.animate_death = 1;
    sfTexture *texture = NULL;
    if (texture == NULL)
        texture = sfTexture_createFromFile("assets/spritesheets/explosion.png",
        NULL);
    sfSprite_setTexture(enemy->entity.sprite, texture, sfFalse);
    sfSprite_setTextureRect(enemy->entity.sprite, (sfIntRect){0, 0, 29, 18});
    if (enemy->id == BLOB)
            sfSprite_setScale(enemy->entity.sprite, (sfVector2f){2.0, 2.0});
    else
        sfSprite_setScale(enemy->entity.sprite, (sfVector2f){0.65, 0.65});
    if (enemy->id == SLIME)
        game->play->stats.nb_killed_slimes++;
    sfSprite_setColor(enemy->entity.sprite, sfWhite);
}

void enemy_handler(game_t *game, object_t *self)
{
    enemy_t *enemy = (enemy_t *)self->data;
    if (enemy->dead)
        return;
    if (!enemy->animation_data.animate_death) {
        animation_enemy_breathing(game, enemy);
        handle_enemy_combat(game, enemy);
        move[enemy->id](game, enemy);
    }
    handle_death_animation(game, enemy);
    if (enemy->stats.life_points <= 0 && !enemy->animation_data.animate_death)
        init_death_state(enemy, game);
}
