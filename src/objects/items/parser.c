/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "my.h"

item_t *create_items(option_t option, int id, sfVector2f pos,
                    int on_the_ground);
option_t get_option_by_id(int id);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
void handle_item(game_t *game, object_t *self);
void draw_item(game_t *game, object_t *self);

void parse_item(game_t *game, region_t *region, char **args)
{
    int i = 0;

    for (; args[i] != 0; ++i)
        if (!my_str_isnum(args[i]))
            return;
    if (i != NB_ARGS_ITEM - 1)
        return;
    int  id = my_getnbr(args[0]);
    if (id < 0 || id >= NB_ITEMS)
        return;

    option_t option = get_option_by_id(id);
    int on_the_ground = my_getnbr(args[1]);
    sfVector2f pos = {my_getnbr(args[2]), my_getnbr(args[3])};
    item_t *item = create_items(option, id, pos, on_the_ground);
    object_t *obj = create_object(ITEMS_OBJ, item, &handle_item, &draw_item);
    my_put_in_list(&region->objects, obj);
}
