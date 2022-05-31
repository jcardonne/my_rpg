/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** events_handler.c
*/

#include "rpg.h"
#include "my.h"

void check_mouse_movement(game_t *game);
void set_game_scene(game_t *game);
void exit_game(game_t *game);

void events_handler_pause_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            exit_game(game);
        check_mouse_movement(game);
        if (game->event.type == sfEvtKeyReleased &&
            game->event.key.code == sfKeyEscape)
            set_game_scene(game);
    }
}