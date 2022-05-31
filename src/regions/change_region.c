/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change_region
*/

#include "game.h"
#include "region.h"
#include <math.h>

void load_region(game_t *game, region_t *region);

int view_reached_destination(sfVector2f *norm_vector, sfVector2f *pos,
sfVector2f *end)
{
    if (norm_vector->x < 0 && pos->x < end->x)
        return (1);
    if (norm_vector->x >= 0 && pos->x > end->x)
        return (1);
    if (norm_vector->y < 0 && pos->y < end->y)
        return (1);
    if (norm_vector->y >= 0 && pos->y > end->y)
        return (1);
    return (0);
}

void animate_region_change(game_t *game)
{
    static long last_clock = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock) / 1000000.0;

    if (diff > 0.01) {
        sfView_move(game->play->view, (sfVector2f){
            game->play->region_animation.direction.x * 15,
            game->play->region_animation.direction.y * 15});
        sfVector2f pos = sfView_getCenter(game->play->view);
        if (view_reached_destination(&game->play->region_animation.direction,
            &pos, &game->play->region_animation.end)) {
            game->play->region_animation.changing = false;
            sfView_setCenter(game->play->view,
                game->play->region_animation.end);
        }
        sfRenderWindow_setView(game->window, game->play->view);
        last_clock = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void change_region(game_t *game, region_t *new_region, int dir_x, int dir_y)
{
    load_region(game, new_region);
    game->play->current_region = new_region;
    game->play->region_animation.changing = true;
    game->play->region_animation.direction = (sfVector2f){dir_x, dir_y};
    game->play->region_animation.start = (sfVector2f){
        game->play->current_region_pos.x * REGION_SIZE_X + REGION_SIZE_X / 2,
        game->play->current_region_pos.y * REGION_SIZE_Y + REGION_SIZE_Y / 2};
    game->play->region_animation.end = (sfVector2f){dir_x * REGION_SIZE_X
        + game->play->region_animation.start.x, dir_y * REGION_SIZE_Y
        + game->play->region_animation.start.y};
    game->play->current_region_pos.x += dir_x;
    game->play->current_region_pos.y += dir_y;
    CAST_PLAYER(game->play->player->data)->emitters = NULL;
}
