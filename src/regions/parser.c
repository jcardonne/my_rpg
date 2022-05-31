/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** parser
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "region.h"
#include "game.h"
#include "object.h"
#include "my.h"

char **cut_str(char *input, char *delimiter);
void parse_teleporter(game_t *game, region_t *region, char **args);
void parse_dialogue_box(game_t *game, region_t *region, char **argv);
void parse_smoke(game_t *game, region_t *region, char **args);
void parse_wave(game_t *game, region_t *region, char **args);
void parse_enemy(game_t *game, region_t *region, char **argv);
void parse_border_wave(game_t *game, region_t *region, char **args);
void parse_npc(game_t *game, region_t *region, char **argv);
void parse_music(game_t *game, region_t *region, char **argv);
void parse_item(game_t *game, region_t *region, char **args);
void parse_grass(game_t *game, region_t *region, char **args);

void (* const PARSE_OBJECT[OBJECT_NB])(game_t *, region_t *, char **) = {
    &parse_teleporter,
    &parse_dialogue_box,
    &parse_smoke,
    &parse_wave,
    &parse_enemy,
    &parse_border_wave,
    NULL,
    NULL,
    NULL,
    &parse_npc,
    &parse_music,
    &parse_item,
    &parse_grass
};

static void execute_create_function(game_t *game, region_t *region,
int object_id, char **args)
{
    if (game->debug_mode)
        my_fprintf(1, "\tCreating object ID '%d'\n", object_id);
    PARSE_OBJECT[object_id](game, region, &args[1]);
}

int parse_region(game_t *game, region_t *region)
{
    char *line = NULL;
    char **args = NULL;
    size_t size = 0;
    int object_id = -1;
    FILE *file = fopen(REGION_PATH[region->id], "r");
    if (file == NULL)
        return -1;
    while (getline(&line, &size, file) != -1) {
        line[my_strlen(line) - 1] = line[my_strlen(line) - 1] == '\n' ?
            '\0' : line[my_strlen(line) - 1];
        args = cut_str(line, " ");
        if (args == NULL || args[0] == NULL || !my_str_isnum(args[0]))
            continue;
        object_id = my_getnbr(args[0]);
        if (object_id < 0 || object_id >= OBJECT_NB
            || PARSE_OBJECT[object_id] == NULL)
            continue;
        execute_create_function(game, region, object_id, args);
    }
    fclose(file);
    return 0;
}
