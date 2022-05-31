/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** sound
*/

#include "game.h"
#include "audio.h"

void play_sound(game_t *game, sfSound *sound)
{
    sfSound_setVolume(sound, game->settings.general_volume);
    sfSound_play(sound);
}
