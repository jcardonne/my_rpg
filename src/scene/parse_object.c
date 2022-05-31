/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parse_object.c
*/

#include "rpg.h"
#include <stdio.h>
#include "my.h"

void parse_button(game_t *game, char **args, int id, int scene);
char **cut_str(char *str, char *delim);

static void (* const PARSE_OBJ_SCENE[])(game_t *, char **, int, int) = {
    &parse_button,
};

void parse_objects_scene(game_t *game, int scene, char *path)
{
    char *line = NULL;
    char **args = NULL;
    size_t size = 0;
    int object_id = -1;
    FILE *fp = fopen(path, "r");

    if (fp == NULL)
        return;
    while (getline(&line, &size, fp) != -1) {
        args = cut_str(line, " ");
        if (args == NULL || args[0] == NULL || !my_str_isnum(args[0]))
            continue;
        object_id = my_getnbr(args[0]);
        if (object_id != 0)
            continue;
        PARSE_OBJ_SCENE[object_id](game, args, object_id, scene);
    }
    fclose(fp);
    free(line);
}
