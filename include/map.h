/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "mylist.h"
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    typedef struct map_s {
        int id;
        bool is_loaded;
        sfSprite *background;
        sfSprite *foreground;
        sfImage *collision;
    } map_t;

    const static char *MAP_PATH[] = {
        "assets/images/maps/base/",
        "assets/images/maps/start_house_interior/",
        "assets/images/maps/mine_interior/",
        "assets/images/maps/mine_house_interior/",
        "assets/images/maps/boss_dungeon/"
    };

    enum {
        BASE_MAP,
        START_HOUSE_MAP,
        MINE_INTERIOR_MAP,
        MINE_HOUSE_INTERIOR_MAP,
        BOSS_DUNGEON_MAP,
        MAP_NB
    };

#endif /* !MAP_H_ */
