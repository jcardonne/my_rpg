/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cursor
*/

#include "rpg.h"

void draw_cursor(sfRenderWindow *window, cursor_t *cursor)
{
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setTextureRect(cursor->sprite, cursor->rect);
    sfSprite_setPosition(cursor->sprite, cursor->pos);
    sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
}
