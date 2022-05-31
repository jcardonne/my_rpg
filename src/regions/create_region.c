/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_region
*/

#include "game.h"
#include "region.h"
#include "my.h"

int parse_region(game_t *game, region_t *region);
void load_map(game_t *game, map_t *map);
void load_music(game_t *game, region_t *new_region);

region_t *create_region(game_t *game, int id)
{
    region_t *region = malloc(sizeof(region_t));
    region->id = id;
    region->is_loaded = false;
    region->top = NULL;
    region->right = NULL;
    region->left = NULL;
    region->bottom = NULL;
    region->objects = NULL;
    region->music_path = NULL;
    region->map = game->play->map_list[REGION_MAP_JMP_TABLE[id]];
    return (region);
}

void load_region(game_t *game, region_t *region)
{
    if (region->is_loaded) {
        load_music(game, region);
        return;
    }
    if (game->debug_mode)
        my_fprintf(2, "\nLoading region ID '%d' '%s'\n", region->id,
            REGION_PATH[region->id]);
    load_map(game, region->map);
    parse_region(game, region);
    load_music(game, region);
    region->is_loaded = true;
}

static region_t *get_link(game_t *game, enum region_ids id, int direction)
{
    enum region_ids link_id = REGION_LINKS[id][direction];
    if (link_id == -1)
        return NULL;
    else
        return game->play->region_list[link_id];
}

void link_regions(game_t *game)
{
    for (int i = 0; i < REGION_NB; ++i) {
        game->play->region_list[i]->top = get_link(game, i, 0);
        game->play->region_list[i]->bottom = get_link(game, i, 1);
        game->play->region_list[i]->left = get_link(game, i, 2);
        game->play->region_list[i]->right = get_link(game, i, 3);
    }
}

void init_all_regions(game_t *game)
{
    for (int id = 0; id < REGION_NB; ++id)
        game->play->region_list[id] = create_region(game, id);
    game->play->current_region = NULL;
    load_region(game, game->play->region_list[START_HOUSE_INTERIOR]);
    game->play->current_region = game->play->region_list[START_HOUSE_INTERIOR];
    game->play->current_region_pos = (sfVector2i){START_REGION_X,
        START_REGION_Y};
    link_regions(game);
    game->play->region_animation.changing = false;
    game->play->start_region = game->play->region_list[START_HOUSE_INTERIOR];
}
