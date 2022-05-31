/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "my.h"

grass_t *create_grass(sfVector2f pos);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
void handler_grass(game_t *game, object_t *self);
void draw_grass(game_t *game, object_t *self);

void parse_grass(game_t *game, region_t *region, char **args)
{
    int i = 0;

    for (; args[i] != 0; ++i) {
        if (!my_str_isnum(args[i]))
            return;
    }
    if (i != NB_ARGS_GRASS)
        return;
    grass_t *grass = create_grass((sfVector2f){my_getnbr(args[0]),
                    my_getnbr(args[1])});
    if (grass == NULL)
        return;
    object_t *obj = create_object(GRASS_OBJ, grass, &handler_grass,
                                &draw_grass);
    obj->id = GRASS_OBJ;
    my_put_in_list(&region->objects, obj);
}
