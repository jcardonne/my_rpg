/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_handler
*/

#include "rpg.h"
#include <stdio.h>

void player_idle_animation(game_t *game);
void move_player(game_t *game, player_t *player, float shift_x, float shift_y);
void interact_player(game_t *game);
void rect_set_y(game_t *game, int status);
void player_attack(game_t *game, player_t *player);
item_t *get_selected_item(game_t *game);

void handle_movement(game_t *game, player_t *player, float new_speed)
{
    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = IDLE_STATE;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        rect_set_y(game, LEFT);
        move_player(game, game->play->player->data, -new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        rect_set_y(game, UP);
        move_player(game, game->play->player->data, 0, -new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rect_set_y(game, RIGHT);
        move_player(game, game->play->player->data, new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        rect_set_y(game, DOWN);
        move_player(game, game->play->player->data, 0, new_speed);
    }
}

void handle_interaction(game_t *game, player_t *player)
{
    long static last_attack = 0;
    if (player->hit_delay) {
        long current_us =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
        double diff = (current_us - last_attack) / 1000000.0;
        if (diff >= 0.2) {
            player->hit_delay = 0;
            last_attack =
                sfClock_getElapsedTime(game->clock->clock).microseconds;
        }
    }
    player_attack(game, player);
}

void handle_combat(game_t *game, player_t *player)
{
    static long invincibility = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - invincibility) / 1000000.0;
    if (player->is_hit) {
        if (diff >= 0.5) {
            player->is_hit = 0;
            sfSprite_setColor(player->entity.sprite, sfWhite);
            invincibility = 0;
        } else {
            sfColor color_hit = {250, 100, 100, 255};
            sfSprite_setColor(player->entity.sprite, color_hit);
        }
    } else
        invincibility = current_us;
}

void handler_player(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    player_t *player = ((player_t *)(game->play->player->data));
    double new_speed = ((player_t *)(game->play->player->data))->speed
        * diff;
    item_t *held = get_selected_item(game);
    if (held != NULL)
        player->attack = held->attack_value;
    else
        player->attack = 1;
    if (!player->hit_delay)
        handle_movement(game, player, new_speed);
    handle_interaction(game, player);
    handle_combat(game, player);
    if (CAST_PLAYER(game->play->player->data)->entity.animation_state
        == IDLE_STATE && !player->hit_delay)
        player_idle_animation(game);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}

void set_player_animation_settings(game_t *game, int status)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t *inventory = &player->inventory;
    item_t *item = get_selected_item(game);

    if (item == NULL)
        return;
    sfSprite *sprite = item->entity->sprite;
    player->orientation = status;
    if (status == 0)
        sfSprite_setRotation(sprite, 90.0);
    if (status == 1)
        sfSprite_setRotation(sprite, 270.0);
    if (status == 2)
        sfSprite_setRotation(sprite, 180.0);
    if (status == 3)
        sfSprite_setRotation(sprite, 0.0);
}
