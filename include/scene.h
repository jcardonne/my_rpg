/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** scene.h
*/

#ifndef SCENE_H
    #define SCENE_H

    #include "particles.h"
    #include "mylist.h"
    #include "object.h"

    enum scenes {
        START_SCENE,
        GAME_SCENE,
        SETTINGS_SCENE,
        PAUSE_SCENE,
        HELP_SCENE,
        INVENTORY_SCENE,
        DEATH_SCENE,
        END_SCENE_BLOB,
        NB_SCENE,
    };

    typedef struct scene {
        linked_list_t *obj;
        int nb_buttons;
        sfTexture *texture_background_saved;
        particles_emitter_t *emitter;
    } scene_t;

#endif