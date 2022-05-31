/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_scene
*/

#include "game.h"
#include "region.h"

void init_game(game_t *game);
void init_scene_objects(game_t *game);

void set_menu_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = START_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}

void set_settings_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = SETTINGS_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}

void set_help_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = HELP_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}
