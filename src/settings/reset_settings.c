/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** reset_settings.c
*/

#include "rpg.h"

void refresh_music_volume(game_t *game)
{
    float calc = game->settings.volume_music
        - (100 - game->settings.general_volume);
    if (game->audio.music == NULL || calc < 0 || calc > 100)
        return;
    sfMusic_setVolume(game->audio.music, calc);
}

void reset_settings(game_t *game)
{
    game->settings.general_volume = 100;
    game->settings.volume_music = 100;
    refresh_music_volume(game);
}
