/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** attack.c
*/

#include "rpg.h"

void rect_set_y(game_t *game, int status);
void interact_player(game_t *game);
int handle_enemies_collisions(object_t *obj, entity_t *entity, game_t *game);
void hit_enemy(enemy_t *enemy, int attack, game_t *game);
void set_pos_hit(player_t *player, sfVector2f pos);
void collisions_with_sword(game_t *game, object_t *obj, item_t *sword);
item_t *get_selected_item(game_t *game);

void handle_items_collisions(game_t *game, player_t *player)
{
    linked_list_t *tmp = game->play->current_region->objects;
    object_t *obj;
    item_t *item_entity = get_selected_item(game);
    if (item_entity == NULL)
        return;
    while (tmp != NULL) {
        obj = tmp->data;
        collisions_with_sword(game, obj, item_entity);
        tmp = tmp->next;
    }
}

static void attack_animation(game_t *game, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) && !player->hit_delay) {
        rect_set_y(game, RIGHT);
        interact_player(game);
        player->hit_delay = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && !player->hit_delay) {
        rect_set_y(game, LEFT);
        interact_player(game);
        player->hit_delay = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !player->hit_delay) {
        rect_set_y(game, DOWN);
        interact_player(game);
        player->hit_delay = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !player->hit_delay) {
        rect_set_y(game, UP);
        interact_player(game);
        player->hit_delay = 1;
    }
}

void player_attack(game_t *game, player_t *player)
{
    if (player->hit_delay) {
        interact_player(game);
        handle_items_collisions(game, player);
        return;
    }
    attack_animation(game, player);
    if (player->hit_delay)
        handle_items_collisions(game, player);
}