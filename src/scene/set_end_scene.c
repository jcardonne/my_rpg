/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** set_end_scene.c
*/

#include "rpg.h"

void set_end_blob_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfTexture_updateFromRenderWindow(texture, game->window, 0, 0);
    game->scene[END_SCENE_BLOB]->texture_background_saved = texture;
    game->current_scene = END_SCENE_BLOB;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}
