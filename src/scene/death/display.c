/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"

void event_handler_death_scene(game_t *game);
void handle_object(game_t *game);
void draw_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

static void animate_death_zoom(game_t *game)
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
        game->play->intro_animation.zoom_factor -= 0.02;
        sfRenderWindow_setView(game->window, game->play->view);
        last_clock = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

static void draw_background(game_t *game)
{
    static sfColor color = {255, 255, 255, 255};
    sfSprite *sprite_background = sfSprite_create();
    sfSprite *sprite_death_text = sfSprite_create();
    static sfTexture *texture = NULL;

    if (texture == NULL)
        texture =
            sfTexture_createFromFile(
                    "assets/images/background_death.png", NULL);
    sfSprite_setTexture(sprite_death_text, texture, sfFalse);
    sfSprite_setPosition(sprite_death_text, (sfVector2f){0, 0});
    sfSprite_setTexture(sprite_background,
                game->scene[DEATH_SCENE]->texture_background_saved, sfFalse);
    sfSprite_setColor(sprite_background, color);
    sfRenderWindow_drawSprite(game->window, sprite_background, NULL);
    sfRenderWindow_drawSprite(game->window, sprite_death_text, NULL);
    if (color.a != 0)
        color.a -= 1;
}

void death_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    event_handler_death_scene(game);
    handle_object(game);
    if (game->current_scene != DEATH_SCENE)
        return;
    draw_background(game);
    draw_scene(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}