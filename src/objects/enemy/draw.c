/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw
*/

#include "game.h"
#include "object.h"

static void debug_draw(game_t *game, object_t *self)
{
    return;
}

static void draw_enemy_emitters(enemy_t *enemy, game_t *game)
{
    linked_list_t *tmp = enemy->emitters;

    while (tmp != NULL) {
        particles_emitter_t *emitter = tmp->data;
        emitter->ptr_part(emitter, BLOOD, emitter->pos, game->window);
        tmp = tmp->next;
    }
}

void draw_enemy(game_t *game, object_t *self)
{
    enemy_t *enemy = self->data;
    draw_enemy_emitters(enemy, game);
    if (enemy->dead)
        return;
    sfRenderWindow_drawSprite(game->window, enemy->entity.sprite, NULL);
    if (game->debug_mode) {
        debug_draw(game, self);
        return;
    }
}
