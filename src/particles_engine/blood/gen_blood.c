/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** gen_blood.c
*/

#include "rpg.h"

int get_random_seed(void);
float gen_random_in_range(float lower, float upper);
sfVector2f calc_vector(sfVector2f point1, sfVector2f point2);

static particles_t init_center(int x, int y)
{
    particles_t center;
    sfVertex vertex_center;
    vertex_center.position.x = x;
    vertex_center.position.y = y;
    vertex_center.color = (sfColor){110, 2, 2, 200};
    vertex_center.texCoords.x = 0;
    vertex_center.texCoords.y = 0;
    center.vertex = vertex_center;
    return center;
}

static particles_t init_blood_part(sfVertex center)
{
    particles_t part;
    part.updated = 0;
    part.is_alive = 1;
    sfVertex vertex;
    vertex.position.x = gen_random_in_range(-2, 2) + center.position.x;
    vertex.position.y = gen_random_in_range(-2, 2) + center.position.y;
    vertex.color = (sfColor){110, 2, 2, 200};
    vertex.texCoords.x = 0;
    vertex.texCoords.y = 0;
    part.vertex = vertex;
    part.direction = calc_vector(center.position, vertex.position);
    return part;
}

static void gen_splatter(particles_t *particles, int nb_splat, sfVector2f pos)
{
    srand(get_random_seed());
    particles[0] = init_center(pos.x, pos.y);
    particles[0].is_alive = 1;
    for (int i = 1; i < nb_splat; ++i)
        particles[i] = init_blood_part(particles[0].vertex);
}

void gen_blood(particles_emitter_t *emitter, sfVector2f pos)
{
    if (emitter->is_gen)
        return;
    emitter->nb_particles = 100;
    emitter->particles = malloc(sizeof(particles_t) * emitter->nb_particles);
    emitter->is_gen = 1;
    emitter->last_updated = 0;
    gen_splatter(emitter->particles, emitter->nb_particles, pos);
    emitter->updates = rand() % 5 + 3;
}