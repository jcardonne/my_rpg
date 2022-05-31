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

void draw_hearts_ui_object(game_t *game, object_t *self)
{
    sfSprite *sprite = self->data;
    int i = 0;

    sfSprite_setPosition(sprite, (sfVector2f){257, 71});
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 70, 70});
    for (; i < CAST_PLAYER(game->play->player->data)->health; ++i) {
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        sfSprite_move(sprite, (sfVector2f){112, 0});
    }
    sfSprite_setTextureRect(sprite, (sfIntRect){70, 0, 70, 70});
    for (; i < 3; ++i) {
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        sfSprite_move(sprite, (sfVector2f){112, 0});
    }
}

void handler_hearts_ui_object(game_t *game, object_t *self)
{
    return;
}

object_t *init_hearts_ui_object(game_t *game)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite,
        sfTexture_createFromFile("assets/spritesheets/hearts.png", NULL),
            sfFalse);
    return create_object(HEARTS_UI_OBJ, sprite,
                    &handler_hearts_ui_object, &draw_hearts_ui_object);
}
