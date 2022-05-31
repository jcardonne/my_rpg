/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create.c
*/

#include "object.h"
#include "ui.h"
#include "my.h"
#include "game.h"
#include <string.h>

button_t *init_button(sfIntRect rect, sfVector2f pos_btn,
                    void (*ptr_btn)(game_t *), int id)
{
    button_t *button = malloc(sizeof(button_t));
    static sfTexture *texture = NULL;
    if (texture == NULL)
        texture = sfTexture_createFromFile("assets/spritesheets/buttons.png",
                                            NULL);
    if (pos_btn.x < 0 || pos_btn.y < 0)
        return NULL;
    button->state = IDLE;
    button->id_btn = id;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, texture, sfFalse);
    sfSprite_setTextureRect(button->sprite, rect);
    sfSprite_setScale(button->sprite, (sfVector2f){3.0, 3.0});
    sfSprite_setPosition(button->sprite, (sfVector2f){pos_btn.x, pos_btn.y});
    button->on_click = ptr_btn;
    return button;
}
