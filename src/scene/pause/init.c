/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"

particles_emitter_t *init_emitter(void);
void parse_objects_scene(game_t *game, int scene, char *path);

void init_pause_menu(game_t *game)
{
    game->scene[PAUSE_SCENE] = malloc(sizeof(scene_t));
    game->scene[PAUSE_SCENE]->obj = NULL;
    game->scene[PAUSE_SCENE]->emitter = init_emitter();
    game->scene[PAUSE_SCENE]->nb_buttons = 3;
    game->scene[PAUSE_SCENE]->texture_background_saved = NULL;
    parse_objects_scene(game, PAUSE_SCENE, "data/scene/pause.scene");
}
