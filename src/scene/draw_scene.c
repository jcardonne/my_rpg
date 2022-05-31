/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_scene.c
*/

#include "rpg.h"
#include "object.h"

static void draw_scene_objects(game_t *game)
{
    linked_list_t *tmp = game->scene[game->current_scene]->obj;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        obj->draw(game, obj);
        tmp = tmp->next;
    }
}

void draw_scene(game_t *game)
{
    if (game->current_scene != GAME_SCENE) {
        draw_scene_objects(game);
        return;
    }
    sfView *old_view = game->play->view;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
    draw_scene_objects(game);
    sfRenderWindow_setView(game->window, old_view);
}
