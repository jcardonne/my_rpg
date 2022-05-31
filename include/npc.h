/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "rpg.h"
    #include "dialogue.h"
    #include "entity.h"
    #include <stdbool.h>

    enum npc_id {
        START_NPC,
        DOG_NPC,
        NPC_NB
    };

    static const char *NPC_DLG_PATH[NPC_NB] = {
        "data/dialogues/start_ghost.dialogue",
        "data/dialogues/dog.dialogue"
    };

    typedef struct {
        enum npc_id id;
        dialogue_box_t *dialogue;
        entity_t entity;
        int dialogue_index;
        int dialogue_line;
        int dialogue_nb;
        char ***dialogue_list;
        sfVector2f start_pos;
        bool is_talking;
    } npc_t;

    #define CAST_NPC(arg) ((npc_t *)(arg))

#endif /* !NPC_H_ */
