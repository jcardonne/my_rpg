/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

waves_t *create_wave(game_t *game, sfVector2f pos);
void draw_wave(game_t *game, struct object_s *self);
void handler_wave(game_t *game, struct object_s *self);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

void parse_wave(game_t *game, region_t *region, char **args)
{
    int i = 0;

    for (; args[i] != 0; ++i) {
        if (!my_str_isnum(args[i]))
            return;
    }
    if (i != NB_ARGS_WAVES - 1)
        return;
    waves_t *wave = create_wave(game,
                        (sfVector2f){my_getnbr(args[0]), my_getnbr(args[1])});
    if (wave == NULL)
        return;
    object_t *obj =
        create_object(SMOKE_OBJ, wave, &handler_wave, &draw_wave);
    my_put_in_list(&region->objects, obj);
}