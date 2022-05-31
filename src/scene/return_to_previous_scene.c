/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** return_to_previous_scene.c
*/

#include "rpg.h"

void set_pause_scene(game_t *game);
void set_menu_scene(game_t *game);

void return_to_previous_scene(game_t *game)
{
    if (game->previous_scene == PAUSE_SCENE)
        set_pause_scene(game);
    if (game->previous_scene == START_SCENE)
        set_menu_scene(game);
}