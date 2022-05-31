/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** gen_snow.c
*/

#include "rpg.h"

int get_random_seed(void);
float gen_random_in_range(float lower, float upper);

static sfVertex gen_random_vertex(void)
{
    int x_rand = rand() % 1920;
    int y_rand = rand() % 1080;
    sfVertex vertex;

    vertex.position.x = x_rand;
    vertex.position.y = y_rand;
    vertex.color = sfWhite;
    vertex.texCoords.x = 0;
    vertex.texCoords.y = 0;
    return vertex;
}

static void gen_flakes(particles_t *particles, int nb_flakes)
{
    srand(get_random_seed());
    for (int i = 0; i < nb_flakes; ++i) {
        particles_t part;
        part.vertex = gen_random_vertex();
        part.direction.x = gen_random_in_range(-0.3, 0.3);
        part.direction.y = rand() % 4 + 1;
        part.is_alive = 0;
        particles[i] = part;
    }
}

void gen_snow(particles_emitter_t *emitter, int nb_flakes)
{
    if (emitter->is_gen)
        return;
    emitter->nb_particles = nb_flakes;
    emitter->particles = malloc(sizeof(particles_t) * nb_flakes);
    emitter->is_gen = 1;
    gen_flakes(emitter->particles, nb_flakes);
}
