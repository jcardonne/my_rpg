/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

waves_border_t *create_border(game_t *game, sfVector2f pos, int id_rotate,
                            int id_border);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
                        void (*draw)());
void draw_border_wave(game_t *game, object_t *self);
void handler_border_wave(game_t *game, object_t *self);

void parse_border_wave(game_t *game, region_t *region, char **args)
{
    int i = 0;

    for (; args[i] != 0; ++i)
        if (!my_str_isnum(args[i]))
            return;
    if (i != NB_ARGS_BORDER_WAVES - 1)
        return;
    waves_border_t *border = create_border(game,
                        (sfVector2f){my_getnbr(args[1]), my_getnbr(args[2])},
                        my_getnbr(args[3]), my_getnbr(args[0]));
    if (border == NULL)
        return;
    object_t *obj = create_object(WAVES_BORDER_OBJ, border,
                                &handler_border_wave, &draw_border_wave);
    my_put_in_list(&region->objects, obj);
}