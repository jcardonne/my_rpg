/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "my.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);
void events_handler_pause_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

static void draw_background(game_t *game)
{
    sfSprite *sprite_background = sfSprite_create();

    sfSprite_setTexture(sprite_background,
                        game->scene[PAUSE_SCENE]->texture_background_saved,
                        sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite_background, NULL);
}

void pause_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    events_handler_pause_scene(game);
    handle_object(game);
    if (game->current_scene != PAUSE_SCENE)
        return;
    draw_background(game);
    draw_scene(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}