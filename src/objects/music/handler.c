/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** handler
*/

#include "game.h"
#include "audio.h"
#include "region.h"
#include "my.h"
#include <stdio.h>

static bool is_same_music(region_t *region1, region_t *region2)
{
    if (region1 == NULL)
        return false;
    if (region2 == NULL)
        return true;
    if (region2->music_path == NULL)
        return true;
    if (region1->music_path == NULL)
        return false;
    if (my_strcmp(region1->music_path, region2->music_path) == 0)
        return true;
    return false;
}

void load_music(game_t *game, region_t *new_region)
{
    if (is_same_music(game->play->current_region, new_region))
        return;
    if (new_region->music_path == NULL)
        return;
    if (game->audio.music != NULL)
        sfMusic_destroy(game->audio.music);
    game->audio.music = sfMusic_createFromFile(new_region->music_path);
    if (game->audio.music == NULL)
        return;
    sfMusic_setVolume(game->audio.music, game->settings.volume_music);
    sfMusic_setLoop(game->audio.music, sfTrue);
    sfMusic_play(game->audio.music);
}
