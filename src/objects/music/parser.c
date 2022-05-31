/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** parser
*/

#include "game.h"
#include "region.h"
#include <stdio.h>
#include "my.h"
#include "mylist.h"
#include "audio.h"

void parse_music(game_t *game, region_t *region, char **argv)
{
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 1)
        return;
    int music_id = my_getnbr(argv[0]);
    if (music_id < 0 || music_id >= MUSIC_NB)
        return;
    region->music_path = MUSIC_PATH[music_id];
}
