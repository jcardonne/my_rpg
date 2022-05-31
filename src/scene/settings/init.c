/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"
#include "settings.h"
#include <stdio.h>
#include "my.h"

particles_emitter_t *init_emitter(void);
void parse_objects_scene(game_t *game, int scene, char *path);

void init_settings_menu(game_t *game)
{
    game->scene[SETTINGS_SCENE] = malloc(sizeof(scene_t));
    game->scene[SETTINGS_SCENE]->obj = NULL;
    game->scene[SETTINGS_SCENE]->emitter = init_emitter();
    game->scene[SETTINGS_SCENE]->nb_buttons = 4;
    game->scene[SETTINGS_SCENE]->texture_background_saved = NULL;
    parse_objects_scene(game, SETTINGS_SCENE, "data/scene/settings.scene");
}
