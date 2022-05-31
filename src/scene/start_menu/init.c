/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"
#include "object.h"
#include <stdio.h>
#include "my.h"

particles_emitter_t *init_emitter(void);
void parse_objects_scene(game_t *game, int scene, char *path);

void init_start_menu(game_t *game)
{
    game->clock = init_clock();
    game->scene[START_SCENE] = malloc(sizeof(scene_t));
    game->scene[START_SCENE]->obj = NULL;
    game->scene[START_SCENE]->emitter = init_emitter();
    game->scene[START_SCENE]->nb_buttons = 4;
    game->scene[START_SCENE]->texture_background_saved = NULL;
    parse_objects_scene(game, START_SCENE, "data/scene/start_menu.scene");
}