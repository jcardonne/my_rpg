/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw
*/

#include "game.h"
#include "object.h"

void draw_teleporter(game_t *game, struct object_s *self)
{
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){168, 50, 166, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){168, 50, 166, 200});
    }
    teleporter_t *data = self->data;
    sfRectangleShape_setSize(shape, (sfVector2f){data->area.width,
        data->area.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){data->area.left,
        data->area.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}
