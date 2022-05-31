/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "stdio.h"

void handle_region(game_t *game);
void draw_region(game_t *game, region_t *region);
void game_events_handler(game_t *game);
void animate_region_change(game_t *game);
void set_death_scene(game_t *game);

static void animate_intro_zoom(game_t *game)
{
    static long last_clock = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock) / 1000000.0;
    if (diff > 0.01) {
        if (game->play->intro_animation.previous_copy != NULL)
            sfView_destroy(game->play->intro_animation.previous_copy);
        if (game->play->intro_animation.zoom_factor >= 1) {
            game->play->intro_animation.zooming = false;
            game->play->view = game->play->intro_animation.start_view;
            sfRenderWindow_setView(game->window, game->play->view);
            return;
        }
        sfView *new = sfView_copy(game->play->intro_animation.start_view);
        game->play->intro_animation.previous_copy = new;
        game->play->view = new;
        sfView_zoom(new, game->play->intro_animation.zoom_factor);
        game->play->intro_animation.zoom_factor += 0.02;
        sfRenderWindow_setView(game->window, game->play->view);
        last_clock = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

static void start_death_scene(game_t *game)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    sfSprite_setTextureRect(player->entity.sprite, (sfIntRect){0, 64, 16, 16});
    sfSprite_setColor(player->entity.sprite, sfWhite);
    sfRenderWindow_drawSprite(game->window, player->entity.sprite, NULL);
    set_death_scene(game);
}

void game(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        game_events_handler(game);
    handle_region(game);
    if (game->current_scene != GAME_SCENE)
        return;
    sfRenderWindow_clear(game->window, (sfColor){28, 28, 28, 255});
    draw_region(game, game->play->current_region);
    if (game->play->region_animation.changing)
        animate_region_change(game);
    if (game->play->intro_animation.zooming)
        animate_intro_zoom(game);
    sfRenderWindow_display(game->window);
    if (CAST_PLAYER(game->play->player->data)->health <= 0)
        start_death_scene(game);
}
