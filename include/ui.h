/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** ui
*/

#ifndef UI_H_
    #define UI_H_

    #include <SFML/Graphics.h>

    #include "entity.h"
    #include "particles.h"

    #define CAST_BUTTON(arg) ((button_t *)(arg))
    #define NB_ARGS_BUTTON 5
    #define NB_PTR_ID 12

    enum buttons {
        BTN_NEW_GAME,
        BTN_SETTINGS,
        BTN_EXIT,
        BTN_HELP,
        BTN_VOLUME_MUSIC,
        BTN_VOLUME_GENERAL,
        BTN_RESET_SETTINGS,
        BTN_RETURN,
        BTN_CONTINUE,
        BTN_RETRY,
        NB_BUTTONS
    };

    enum button_state {
        IDLE,
        HOVERED,
        CLICKED
    };

    typedef struct cursor_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f pos;
        int mouse_pressed;
        int item_selected_index;
    } cursor_t;

    typedef struct button {
        int id_btn;
        sfSprite *sprite;
        int state;
        void (*on_click)();
    } button_t;

#endif /* !UI_H_ */
