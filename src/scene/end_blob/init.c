/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"

void init_end_blob(game_t *game)
{
    game->scene[END_SCENE_BLOB] = malloc(sizeof(scene_t));
    game->scene[END_SCENE_BLOB]->obj = NULL;
    game->scene[END_SCENE_BLOB]->nb_buttons = 0;
    game->scene[END_SCENE_BLOB]->texture_background_saved = NULL;
}