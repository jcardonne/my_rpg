/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** hit_enemy.c
*/

#include "rpg.h"

particles_emitter_t *init_emitter(void);
void init_bounce(enemy_t *skeleton, game_t *game);

void hit_enemy(enemy_t *enemy, int attack, game_t *game)
{
    particles_emitter_t *emitter = init_emitter();
    emitter->pos = enemy->self_pos;
    my_put_in_list(&enemy->emitters, emitter);
    enemy->stats.life_points -= attack;
    enemy->is_hit = 1;
    if (enemy->id == SKELETON)
        init_bounce(enemy, game);
}
