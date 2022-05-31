/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** settings.h
*/

#ifndef SETTINGS_H
    #define SETTINGS_H

    #include "particles.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    typedef struct settings {
        int volume_music;
        int general_volume;
        sfText *music_text;
        sfText *general_text;
    } settings_t;

#endif