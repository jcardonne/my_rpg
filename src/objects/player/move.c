/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** move.c
*/

#include "rpg.h"

void player_movement_animation(game_t *game);
bool check_entity_region_collision(game_t *game, sfVector2f shift,
                                    entity_t entity, int is_player);
particles_emitter_t *init_emitter(void);
sfVector2f get_pos_player(game_t *game);
void player_hit(game_t *game, player_t *player);
int handle_grass_collisions(object_t *obj, entity_t *entity, game_t *game,
                            sfVector2f shift);

int handle_enemies_collisions(object_t *obj, entity_t *entity, game_t *game)
{
    sfFloatRect rect_entity = sfSprite_getGlobalBounds(entity->sprite);
    if (obj->id == ENEMY_OBJ) {
        enemy_t *enemy = obj->data;
        if (enemy->animation_data.animate_death)
            return 0;
        sfFloatRect rect_enemy =
            sfSprite_getGlobalBounds(enemy->entity.sprite);
        if (sfFloatRect_intersects(&rect_entity, &rect_enemy, NULL))
            return 1;
    }
    return 0;
}

static int handle_collisions(game_t *game, player_t *player, sfVector2f shift)
{
    if (check_entity_region_collision(game, shift,
                            ((player_t *)(game->play->player->data))->entity,
                            1))
        return 1;
    linked_list_t *tmp = game->play->current_region->objects;
    while (tmp != NULL && !player->is_hit) {
        object_t *obj = tmp->data;
        if (handle_enemies_collisions(obj, &player->entity, game)) {
            player_hit(game, player);
            return 1;
        }
        if (handle_grass_collisions(obj, &player->entity, game, shift))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (handle_collisions(game, player, (sfVector2f){shift_x, shift_y}))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    player_movement_animation(game);
}