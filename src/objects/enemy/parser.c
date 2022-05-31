/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser
*/

#include <stdio.h>
#include "my.h"
#include "game.h"
#include "region.h"
#include "object.h"
#include "mylist.h"

object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
enemy_t *create_enemy(sfVector2f *pos, option_t option, stats_t stats);
void draw_enemy(game_t *game, object_t *self);
stats_t blob_stats(void);
stats_t slime_stats(void);
stats_t ghost_stats(void);
stats_t skeleton_stats(void);
option_t blob_option(void);
option_t slime_option(void);
option_t ghost_option(void);
option_t skeleton_option(void);
void enemy_handler(game_t *game, object_t *self);

static stats_t (*stats_enemy[3])(void) = {&blob_stats, &slime_stats,
                                            &skeleton_stats};
static option_t (*option_enemy[3])(void) = {&blob_option, &slime_option,
                                            &skeleton_option};

static sfVector2f *get_pos(char **arg)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 2);

    pos[0] = (sfVector2f){my_getnbr(arg[1]), my_getnbr(arg[2])};
    pos[1] = (sfVector2f){my_getnbr(arg[3]), my_getnbr(arg[4])};
    return pos;
}

void parse_enemy(game_t *game, region_t *region, char **argv)
{
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != NB_ARGS_ENEMY)
        return;
    int id = my_getnbr(argv[0]);
    if (id < 0 || id >= NB_ENEMIES)
        return;
    if (game->debug_mode)
        my_printf("\tParsing enemy ID '%d'\n", id);
    enemy_t *enemy = create_enemy(get_pos(argv), option_enemy[id](),
                                                stats_enemy[id]());
    enemy->id = id;
    if (enemy->id == BLOB)
        sfSprite_setScale(enemy->entity.sprite, (sfVector2f){3.0, 3.0});
    object_t *object = create_object(ENEMY_OBJ, enemy,
                                                &enemy_handler, &draw_enemy);
    my_put_in_list(&region->objects, object);
}
