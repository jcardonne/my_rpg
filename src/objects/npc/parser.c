/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"
#include "npc.h"

object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
void create_npc_start_ghost(game_t *game, object_t *self);
void create_npc_dog(game_t *game, object_t *self);

void (* const CREATE_NPC[NPC_NB])(game_t *game, object_t *self) = {
    &create_npc_start_ghost,
    &create_npc_dog
};

object_t *create_npc_object(game_t *game, enum npc_id npc_id, sfVector2f pos)
{
    npc_t *npc = malloc(sizeof(npc_t));
    object_t *object = malloc(sizeof(object_t));
    object->data = npc;
    npc->id = npc_id;
    npc->start_pos = pos;
    CREATE_NPC[npc_id](game, object);
    return (object);
}

void parse_npc(game_t *game, region_t *region, char **argv)
{
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 3)
        return;
    int npc_id = my_getnbr(argv[0]);
    if (npc_id < 0 || npc_id >= NPC_NB)
        return;
    object_t *obj = create_npc_object(game, npc_id,
                        (sfVector2f){my_getnbr(argv[1]), my_getnbr(argv[2])});
    obj->id = NPC_OBJ;
    my_put_in_list(&region->objects, obj);
}
