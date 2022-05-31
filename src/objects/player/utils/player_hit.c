/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** player_hit.c
*/

#include "rpg.h"

sfVector2f get_pos_player(game_t *game);
particles_emitter_t *init_emitter(void);

void player_hit(game_t *game, player_t *player)
{
    particles_emitter_t *emitter = init_emitter();
    emitter->pos = get_pos_player(game);
    my_put_in_list(&CAST_PLAYER(game->play->player->data)->emitters,
                    emitter);
    if (!game->debug_mode)
        CAST_PLAYER(game->play->player->data)->health -= 1;
    CAST_PLAYER(game->play->player->data)->is_hit = 1;
}