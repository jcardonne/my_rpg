/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_background.c
*/

#include "rpg.h"

int draw_background_end_blob(game_t *game)
{
    sfSprite *sprite_background = sfSprite_create();
    static sfColor color = {255, 255, 255, 255};

    sfSprite_setTexture(sprite_background,
        game->scene[END_SCENE_BLOB]->texture_background_saved, sfFalse);
    sfSprite_setColor(sprite_background, color);
    sfRenderWindow_drawSprite(game->window, sprite_background, NULL);
    color.a -= 1;
    if (color.a <= 0)
        return 0;
    return 1;
}
