/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"
#include "npc.h"
#include "my.h"

void draw_dialogue_box(game_t *game, dialogue_box_t *dlg);

void draw_npc_start_ghost(game_t *game, object_t *self)
{
    npc_t *npc = CAST_NPC(self->data);
    sfRenderWindow_drawSprite(game->window, npc->entity.sprite, NULL);
    if (npc->is_talking)
        draw_dialogue_box(game, npc->dialogue);
}
