/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** update_snow.c
*/

#include "rpg.h"

float gen_random_in_range(float lower, float upper);

void update_flakes(particles_emitter_t *emitter)
{
    float direction_x = 0;
    float direction_y = 0;

    for (int i = 0; i < emitter->nb_particles; ++i) {
        direction_x = emitter->particles[i].direction.x;
        direction_y = emitter->particles[i].direction.y;
        emitter->particles[i].vertex.position.x += direction_x;
        emitter->particles[i].vertex.position.y += direction_y;
        emitter->particles[i].direction.x = gen_random_in_range(-0.3, 0.3);
        if (emitter->particles[i].vertex.position.y > 1000) {
            emitter->particles[i].is_alive = 0;
            emitter->particles[i].vertex.position.x = rand() % 1920;
            emitter->particles[i].vertex.position.y = rand() % 50 - 50;
            emitter->particles[i].direction.x = gen_random_in_range(-0.3, 0.3);
        }
    }
}
