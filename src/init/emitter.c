/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** emitter.c
*/

#include "rpg.h"

void handle_particles(particles_emitter_t *emitter, int type, sfVector2f pos,
                        sfRenderWindow *win);

particles_emitter_t *init_emitter(void)
{
    particles_emitter_t *emitter = malloc(sizeof(particles_emitter_t));

    emitter->is_gen = 0;
    emitter->nb_particles = 0;
    emitter->last_updated = 0;
    emitter->ptr_part = &handle_particles;
    return emitter;
}
