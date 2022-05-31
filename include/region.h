/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** region
*/

#ifndef REGION_H_
    #define REGION_H_

    #define NB_MAX_INFO 4
    #define REGION_SIZE_X 480
    #define REGION_SIZE_Y 272

    #define INIT_REGION(id) (game->play->region_list[id] = create_region(id))

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include "mylist.h"
    #include "map.h"

    typedef struct regions_s {
        int id;
        linked_list_t *objects;
        struct regions_s *left;
        struct regions_s *right;
        struct regions_s *top;
        struct regions_s *bottom;
        map_t *map;
        bool is_loaded;
        const char *music_path;
    } region_t;

    const static char *REGION_PATH[] = {
        "data/regions/start.region",
        "data/regions/mine.region",
        "data/regions/start_house_interior.region",
        "data/regions/mine_interior_top.region",
        "data/regions/mine_interior_bottom.region",
        "data/regions/mine_interior_left.region",
        "data/regions/slime.region",
        "data/regions/path_to_boss.region",
        "data/regions/mine_house_interior.region",
        "data/regions/boss_dungeon.region"
    };

    enum region_ids {
        START_REGION,
        MINE_REGION,
        START_HOUSE_INTERIOR,
        MINE_INTERIOR_TOP,
        MINE_INTERIOR_BOTTOM,
        MINE_INTERIOR_LEFT,
        SLIME_REGION,
        PATH_TO_BOSS_REGION,
        MINE_HOUSE_INTERIOR_REGION,
        BOSS_DUNGEON_REGION,
        REGION_NB
    };

    const static int REGION_MAP_JMP_TABLE[REGION_NB] = {
        BASE_MAP, // Start_region (id 0) is linked to map id 0 (base map)
        BASE_MAP,
        START_HOUSE_MAP,
        MINE_INTERIOR_MAP,
        MINE_INTERIOR_MAP,
        MINE_INTERIOR_MAP,
        BASE_MAP,
        BASE_MAP,
        MINE_HOUSE_INTERIOR_MAP,
        BOSS_DUNGEON_MAP,
    };

    const static enum region_ids REGION_LINKS[REGION_NB][4] = {
        {MINE_REGION, -1, SLIME_REGION, -1},
        {PATH_TO_BOSS_REGION, START_REGION, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, MINE_INTERIOR_LEFT, -1},
        {MINE_INTERIOR_LEFT, -1, -1, -1}, //Mine interrior bottom
        {-1, MINE_INTERIOR_BOTTOM, -1, MINE_INTERIOR_TOP},
        {-1, -1, -1, START_REGION},
        {-1, MINE_REGION, -1, -1}, //path to boss region
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
    }; //0 : Up, 1 : Down, 2 : Left, 3 : Right

#endif /* !REGION_H_ */
