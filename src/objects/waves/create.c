/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create.c
*/

#include "rpg.h"
#include "object.h"

int get_random_seed(void);

static int offset[] = {
    0, 16, 32, 48, 64, 80
};

waves_t *create_wave(game_t *game, sfVector2f pos)
{
    if (pos.x < 0 || pos.y < 0)
        return NULL;
    srand(get_random_seed());
    waves_t *wave = malloc(sizeof(waves_t));
    wave->pos = pos;
    static sfTexture *texture = NULL;
    if (texture == NULL)
        texture =
            sfTexture_createFromFile("assets/spritesheets/waves.png", NULL);
    wave->sprite = sfSprite_create();
    sfSprite_setPosition(wave->sprite, wave->pos);
    sfSprite_setTexture(wave->sprite, texture, sfFalse);
    sfSprite_setScale(wave->sprite, (sfVector2f){1, 1});
    int rd = rand() % 6;
    wave->offset_x = offset[rd];
    wave->last_clock = 0;
    return wave;
}