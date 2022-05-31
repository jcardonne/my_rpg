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
void events_handler_help_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

static void draw_help(game_t *game)
{
    static sfSprite *background = NULL;
    if (background == NULL) {
        background = sfSprite_create();
        sfTexture *texture_background =
            sfTexture_createFromFile("assets/images/how_to_play.png", NULL);
        sfSprite_setTexture(background, texture_background, sfFalse);
    }
    sfRenderWindow_drawSprite(game->window, background, NULL);
}

void help_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, (sfColor){28, 28, 28, 255});
    events_handler_help_scene(game);
    handle_object(game);
    if (game->current_scene != HELP_SCENE)
        return;
    game->scene[HELP_SCENE]
    ->emitter->ptr_part(game->scene[HELP_SCENE]->emitter, SNOW,
                        (sfVector2f){0.0, 0.0}, game->window);
    draw_scene(game);
    draw_help(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}