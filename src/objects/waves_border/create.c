/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create.c
*/

#include "rpg.h"
#include "object.h"

static int offset_y[4][4] = {
    {0, 0, 32, 32},
    {0, 16, 32, 16},
    {48, 48, 64, 64},
    {80, 80, 96, 96},
};

static int offset_x[4][4] = {
    {0, 32, 32, 0},
    {16, 32, 16, 0},
    {0, 16, 16, 0},
    {0, 16, 144, 144}
};

static void init_spritesheet(waves_border_t *border, int id_rotate,
                            int id_border)
{
    static sfTexture *texture = NULL;
    if (texture == NULL)
        texture =
            sfTexture_createFromFile("assets/spritesheets/waves_border.png",
                                    NULL);
    border->sprite = sfSprite_create();
    border->offset_x = offset_x[id_border][id_rotate];
    border->offset_y = offset_y[id_border][id_rotate];
    sfSprite_setTexture(border->sprite, texture, sfFalse);
    sfSprite_setPosition(border->sprite, border->pos);
}

waves_border_t *create_border(game_t *game, sfVector2f pos, int id_rotate,
                            int id_border)
{
    if (pos.x < 0 || pos.y < 0 || id_rotate < 0 || id_rotate > 3 ||
        id_border < 0 || id_border > 3)
        return NULL;
    waves_border_t *border = malloc(sizeof(waves_border_t));
    border->offset_x = 0;
    border->offset_y = 0;
    border->direction = 1;
    border->last_clock = 0;
    border->pos = pos;
    init_spritesheet(border, id_rotate, id_border);
    return border;
}
