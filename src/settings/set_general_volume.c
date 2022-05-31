/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** set_general_volume.c
*/

#include "rpg.h"

void refresh_music_volume(game_t *game);

void increase_general_volume(game_t *game)
{
    if (game->settings.general_volume >= 100)
        return;
    game->settings.general_volume += 10;
    refresh_music_volume(game);
}

void decrease_general_volume(game_t *game)
{
    if (game->settings.general_volume <= 0) {
        game->settings.general_volume = 0;
        return;
    }
    game->settings.general_volume -= 10;
    refresh_music_volume(game);
}
