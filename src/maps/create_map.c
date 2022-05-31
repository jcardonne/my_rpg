/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_map
*/

#include "game.h"
#include "map.h"
#include "my.h"

char *extend_string(char *first, char *second);

map_t *create_map(int id)
{
    map_t *map = malloc(sizeof(map_t));
    map->id = id;
    map->is_loaded = false;
    map->background = NULL;
    map->foreground = NULL;
    map->collision = NULL;
    return (map);
}

void load_map(game_t *game, map_t *map)
{
    if (map->is_loaded)
        return;
    char *path = (char *)MAP_PATH[map->id];
    if (game->debug_mode)
        my_fprintf(2, "\tLoading map ID '%d' '%s'\n", map->id, path);
    map->background = sfSprite_create();
    map->foreground = sfSprite_create();
    map->collision = sfImage_createFromFile(
        extend_string(path, "collision.png"));
    SET_SPRITE_IMG(map->background,
        extend_string(path, "background.png"), NULL);
    SET_SPRITE_IMG(map->foreground,
        extend_string(path, "foreground.png"), NULL);
    sfSprite_setColor(map->foreground, (sfColor){255, 255, 255, 200});
    map->is_loaded = true;
}

void init_all_maps(game_t *game)
{
    for (int id = 0; id < MAP_NB; ++id)
        game->play->map_list[id] = create_map(id);
}
