/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** dialogue_file_parser
*/

#include "my.h"
#include "npc.h"
#include "game.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char **cut_str(char *str, char *delim);
char *replace_char_by_char(char *str, char c1, char c2);

static void extend_array(char ****array, char **new_line)
{
    int size = 0;
    for (; (*array)[size] != NULL; ++size);
    char ***new_array = malloc(sizeof(char **) * (size + 2));
    for (int i = 0; i < size; ++i)
        new_array[i] = (*array)[i];
    new_array[size] = new_line;
    new_array[size + 1] = NULL;
    free(*array);
    *array = new_array;
}

int parse_dialogue_file(game_t *game, npc_t *npc)
{
    npc->dialogue_list = malloc(sizeof(char **));
    npc->dialogue_list[0] = NULL;
    char *line = NULL, **args = NULL;
    size_t size = 0;
    FILE *file = fopen(NPC_DLG_PATH[npc->id], "r");
    if (file == NULL)
        return -1;
    while (getline(&line, &size, file) != -1) {
        line[my_strlen(line) - 1] = line[my_strlen(line) - 1] == '\n' ?
            '\0' : line[my_strlen(line) - 1];
        args = cut_str(line, " ");
        if (args == NULL || args[0] == NULL)
            continue;
        for (int i = 0; args[i]; ++i)
            replace_char_by_char(args[i], '|', '\n');
        extend_array(&npc->dialogue_list, args);
        ++npc->dialogue_nb;
    }
    fclose(file);
    return 0;
}
