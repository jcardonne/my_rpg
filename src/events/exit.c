/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** exit.c
*/

#include "rpg.h"

static void destroy_audio(game_t *game)
{
    sfMusic_destroy(game->audio.music);
    sfSoundBuffer_destroy(
        (sfSoundBuffer *)sfSound_getBuffer(game->audio.jump));
    sfSoundBuffer_destroy(
        (sfSoundBuffer *)sfSound_getBuffer(game->audio.player_death));
    sfSound_destroy(game->audio.jump);
    sfSound_destroy(game->audio.player_death);
}

void exit_game(game_t *game)
{
    if (game->audio.music != NULL) {
        destroy_audio(game);
    }
    sfRenderWindow_close(game->window);
}
