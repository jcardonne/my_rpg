/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_start.c
*/

#include "rpg.h"
#include "object.h"

static float offset[] = {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static void draw_hovering(float translate, object_t *obj, game_t *game)
{
    sfRenderStates state;
    sfSprite *sprite = sfSprite_copy(CAST_BUTTON(obj->data)->sprite);
    sfTexture *texture = sfTexture_createFromImage(
                    sfImage_createFromColor(100, 100, sfWhite), NULL);

    sfSprite_setTexture(sprite, texture, false);
    state.texture = NULL;
    state.blendMode = (sfBlendMode){sfBlendFactorOneMinusDstColor,
                        sfBlendFactorOneMinusSrcColor, sfBlendEquationAdd};
    state.transform = sfTransform_Identity;
    int id_btn = CAST_BUTTON(obj->data)->id_btn;
    if (id_btn >= 7)
        sfTransform_translate(&state.transform, 0, -translate);
    else
        sfTransform_translate(&state.transform, translate, 0);
    state.shader = NULL;
    sfRenderWindow_drawSprite(game->window, sprite, &state);
}

static sfRenderStates create_state_button(float translate, object_t *obj)
{
    sfRenderStates state;
    state.texture = NULL;
    state.blendMode = sfBlendNone;
    state.transform = sfTransform_Identity;
    int id_btn = CAST_BUTTON(obj->data)->id_btn;
    if (id_btn >= 7)
        sfTransform_translate(&state.transform, 0, -translate);
    else
        sfTransform_translate(&state.transform, translate, 0);
    state.shader = NULL;
    return state;
}

void draw_buttons_start(game_t *game, object_t *button)
{
    sfRenderStates state =
        create_state_button(offset[CAST_BUTTON(button->data)->id_btn], button);

    if (CAST_BUTTON(button->data)->state == IDLE) {
        if (offset[CAST_BUTTON(button->data)->id_btn] != 0)
            offset[CAST_BUTTON(button->data)->id_btn]--;
        sfRenderWindow_drawSprite(game->window,
                                CAST_BUTTON(button->data)->sprite, &state);
    } else if (CAST_BUTTON(button->data)->state == HOVERED) {
        sfRenderWindow_drawSprite(game->window,
                                CAST_BUTTON(button->data)->sprite, &state);
        draw_hovering(offset[CAST_BUTTON(button->data)->id_btn], button, game);
        if (offset[CAST_BUTTON(button->data)->id_btn] < 25)
            offset[CAST_BUTTON(button->data)->id_btn]++;
    }
}
