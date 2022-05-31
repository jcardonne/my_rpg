/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** particles_engine.c
*/

#include "rpg.h"

void gen_snow(particles_emitter_t *emitter, int nb_flakes);
void update_flakes(particles_emitter_t *emitter);
void draw_particles(sfRenderWindow *win, particles_emitter_t *emitter,
                    int type);
void gen_blood(particles_emitter_t *emitter, sfVector2f pos);
void update_blood(particles_t *particles, int nb_particles, int updates);

static void handle_snow(particles_emitter_t *emitter, sfRenderWindow *win)
{
    gen_snow(emitter, 1000);
    update_flakes(emitter);
    draw_particles(win, emitter, SNOW);
}

void handle_blood(particles_emitter_t *emitter, sfVector2f pos,
                sfRenderWindow *win)
{
    gen_blood(emitter, pos);
    update_blood(emitter->particles, emitter->nb_particles, emitter->updates);
    draw_particles(win, emitter, BLOOD);
}

void handle_particles(particles_emitter_t *emitter, int type, sfVector2f pos,
                        sfRenderWindow *win)
{
    switch (type) {
        case SNOW:
            handle_snow(emitter, win);
            break;
        case BLOOD:
            handle_blood(emitter, pos, win);
            break;
        default:
            break;
    }
}