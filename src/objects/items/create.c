/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"

void sword_hit_effect(game_t *game, item_t *sword);

static int (attack_values[]) = {
    3, 0
};

static void (*ptr_hit_effect[]) = {
    &sword_hit_effect,
    NULL,
};

item_t *create_items(option_t option, int id, sfVector2f pos,
                    int on_the_ground)
{
    item_t *item = malloc(sizeof(item_t));

    option.pos = pos;
    item->entity = init_entity(option);
    item->name = option.name ? option.name : NULL;
    item->on_the_ground = on_the_ground;
    item->unlocked = 0;
    item->hit_effect = 0;
    item->sprite_effect = sfSprite_create();
    item->id = id;
    item->handle_hit = ptr_hit_effect[id];
    item->attack_value = attack_values[id];
    return item;
}
