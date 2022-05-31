/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** events_handler.c
*/

#include "rpg.h"

void check_mouse_movement(game_t *game);
void exit_game(game_t *game);

void event_handler_death_scene(game_t *game)
{
    check_mouse_movement(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            exit_game(game);
    }
}
