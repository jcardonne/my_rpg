/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** background
*/

#include <stddef.h>
#include <stddef.h>
#include "game.h"
#include "my.h"

int my_put_in_list(struct linked_list **list, void *data);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

void draw_background_ui_object(game_t *game, object_t *self)
{
    sfSprite *sprite = self->data;
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}

void handler_background_ui_object(game_t *game, object_t *self)
{
    return;
}

object_t *init_background_ui_object(game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite,
        sfTexture_createFromFile("assets/images/game_ui.png", NULL), sfFalse);
    return create_object(BACKGROUND_UI_OBJ, sprite,
                    &handler_background_ui_object, &draw_background_ui_object);
}
