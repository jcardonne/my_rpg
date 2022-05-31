/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

smoke_t *create_smoke(game_t *game, sfVector2f pos);
void draw_smoke(game_t *game, struct object_s *self);
void handler_smoke(game_t *game, struct object_s *self);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

void parse_smoke(game_t *game, region_t *region, char **args)
{
    int i = 0;

    for (; args[i] != 0; ++i) {
        if (!my_str_isnum(args[i]))
            return;
    }
    if (i != NB_ARGS_SMOKE - 1)
        return;
    smoke_t *smoke = create_smoke(game,
                        (sfVector2f){my_getnbr(args[0]), my_getnbr(args[1])});
    if (smoke == NULL)
        return;
    object_t *obj =
        create_object(SMOKE_OBJ, smoke, &handler_smoke, &draw_smoke);
    my_put_in_list(&region->objects, obj);
}
