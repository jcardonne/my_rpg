/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler_start.c
*/

#include "rpg.h"
#include "object.h"

void handle_button_event_start(game_t *game, object_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect_text =
        sfSprite_getGlobalBounds(CAST_BUTTON(button->data)->sprite);
    sfBool contained = sfFloatRect_contains(&rect_text, mouse_pos.x,
                                            mouse_pos.y);

    if (contained == sfTrue && sfMouse_isButtonPressed(sfMouseLeft))
        sfSprite_setColor(CAST_BUTTON(button->data)->sprite,
                        (sfColor){200, 200, 200, 255});
    if (contained == sfTrue && game->cursor->mouse_pressed == 1) {
        game->cursor->mouse_pressed = 0;
        CAST_BUTTON(button->data)->state = CLICKED;
        sfSprite_setColor(CAST_BUTTON(button->data)->sprite, sfWhite);
        CAST_BUTTON(button->data)->on_click(game);
    } else if (contained == sfTrue) {
        CAST_BUTTON(button->data)->state = HOVERED;
    } else {
        sfSprite_setColor(CAST_BUTTON(button->data)->sprite, sfWhite);
        CAST_BUTTON(button->data)->state = IDLE;
    }
}
