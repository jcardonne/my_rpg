/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** window
*/

#include "rpg.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Tinim", sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    return (window);
}
