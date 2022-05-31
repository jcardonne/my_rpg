/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cursor
*/

#include "rpg.h"

cursor_t *init_cursor(sfRenderWindow *window)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    cursor->texture =
        sfTexture_createFromFile("assets/spritesheets/aim.png", NULL);
    cursor->sprite = sfSprite_create();
    cursor->rect = (sfIntRect){88, 154, 22, 22};
    cursor->pos.x = pos.x;
    cursor->pos.y = pos.y;
    cursor->mouse_pressed = 0;
    cursor->item_selected_index = -1;
    return (cursor);
}
