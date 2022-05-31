/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "mylist.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    enum object_animation_state {
        IDLE_STATE,
        MOVEMENT_STATE,
        INTERACTION_STATE,
    };

    typedef struct entity_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        enum object_animation_state animation_state;
        int spritesheet_rect_x; // Décalage d'image sur spritesheet par pixel (spritesheet horizontal)
        int spritesheet_rect_y; // Décalage d'image sur spritesheet par pixel (spritesheet vertical)
        int spritesheet_width; // total image width (in pixels)
        int spritesheet_height; // total image height (in pixels)
    } entity_t;

#endif /* !ENTITY_H_ */
