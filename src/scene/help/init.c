/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"

particles_emitter_t *init_emitter(void);
void parse_objects_scene(game_t *game, int scene, char *path);

void init_help_menu(game_t *game)
{
    game->scene[HELP_SCENE] = malloc(sizeof(scene_t));
    game->scene[HELP_SCENE]->obj = NULL;
    game->scene[HELP_SCENE]->emitter = init_emitter();
    game->scene[HELP_SCENE]->nb_buttons = 1;
    game->scene[HELP_SCENE]->texture_background_saved = NULL;
    parse_objects_scene(game, HELP_SCENE, "data/scene/help.scene");
}