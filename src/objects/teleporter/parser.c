/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** parser
*/

#include "game.h"
#include "region.h"
#include "object.h"
#include <stdio.h>
#include "my.h"
#include "mylist.h"

teleporter_t *create_teleporter_data(region_t *dest_region, sfFloatRect area);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
void teleporter_handler(game_t *game, struct object_s *self);
void draw_teleporter(game_t *game, struct object_s *self);

void dungeon_teleporter_handler(game_t *game, struct object_s *self);

void parse_teleporter(game_t *game, region_t *region, char **argv)
{
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 6)
        return;
    int region_id = my_getnbr(argv[0]);
    if (region_id < 0 || region_id >= REGION_NB)
        return;
    teleporter_t *teleporter = create_teleporter_data(
        game->play->region_list[region_id], (sfFloatRect){my_getnbr(argv[1]),
            my_getnbr(argv[2]), my_getnbr(argv[3]), my_getnbr(argv[4])
        });
    object_t *object = create_object(TELEPORTER_OBJ, teleporter,
        my_getnbr(argv[5]) ? &dungeon_teleporter_handler : &teleporter_handler,
        &draw_teleporter);
    my_put_in_list(&region->objects, object);
}
