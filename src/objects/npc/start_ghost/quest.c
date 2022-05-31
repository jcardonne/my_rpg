/*
** EPITECH PROJECT, 2022
** myrpg [WSL: Ubuntu]
** File description:
** quest
*/

#include "game.h"
#include "npc.h"

int is_equipped(game_t *game, int id);
void dialogue_box_set_text(dialogue_box_t *dialogue, char *text);

void handle_quest(game_t *game, npc_t *npc)
{
    static bool slime_killed = false;
    if (game->game_end && npc->dialogue_nb >= 5) {
        npc->dialogue_line = 4;
        return;
    }
    if (is_equipped(game, KEY) && npc->dialogue_nb >= 4) {
        npc->dialogue_line = 3;
        return;
    }
    if ((game->play->stats.nb_killed_slimes == 4 || slime_killed)
        && npc->dialogue_nb >= 3) {
        npc->dialogue_line = 2;
        slime_killed = true;
        return;
    }
    if (is_equipped(game, SWORD) && npc->dialogue_nb >= 2) {
        npc->dialogue_line = 1;
        return;
    }
    npc->dialogue_line = 0;
}