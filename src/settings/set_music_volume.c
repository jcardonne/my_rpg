/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** set_music_volume.c
*/

#include "rpg.h"

void refresh_music_volume(game_t *game);

void increase_music_volume(game_t *game)
{
    if (game->settings.volume_music >= 100)
        return;
    game->settings.volume_music += 10;
    refresh_music_volume(game);
}

void decrease_music_volume(game_t *game)
{
    if (game->settings.volume_music <= 0) {
        game->settings.volume_music = 0;
        return;
    }
    game->settings.volume_music -= 10;
    refresh_music_volume(game);
}
