/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** update_blood.c
*/

#include "rpg.h"

static void kill_particles(particles_t *particles, int nb_particles)
{
    for (int i = 0; i < nb_particles; ++i) {
        if (particles[i].is_alive)
            particles[i].is_alive = 0;
        else
            break;
    }
}

void update_blood(particles_t *particles, int nb_particles, int updates)
{
    for (int i = 0; i < nb_particles; ++i) {
        if (particles[i].is_alive) {
            particles[i].vertex.position.x += particles[i].direction.x;
            particles[i].vertex.position.y += particles[i].direction.y;
            particles[i].updated++;
        } else
            break;
        if (particles[i].updated > updates) {
            kill_particles(particles, nb_particles);
            break;
        }
    }
}