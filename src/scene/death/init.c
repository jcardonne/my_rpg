/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"

void parse_objects_scene(game_t *game, int scene, char *path);

void init_death_menu(game_t *game)
{
    game->scene[DEATH_SCENE] = malloc(sizeof(scene_t));
    game->scene[DEATH_SCENE]->obj = NULL;
    game->scene[DEATH_SCENE]->nb_buttons = 2;
    game->scene[DEATH_SCENE]->texture_background_saved = NULL;
    parse_objects_scene(game, DEATH_SCENE, "data/scene/death.scene");
}
