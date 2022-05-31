/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** collisions_with_sword.c
*/

#include "rpg.h"

int handle_enemies_collisions(object_t *obj, entity_t *entity, game_t *game);
void set_pos_hit(game_t *game, sfVector2f pos);
void hit_enemy(enemy_t *enemy, int attack, game_t *game);

int handle_grass_collisions(object_t *obj, entity_t *entity, game_t *game,
                            sfVector2f shift)
{
    sfFloatRect rect_entity = sfSprite_getGlobalBounds(entity->sprite);
    rect_entity.left += shift.x;
    rect_entity.top += shift.y;
    if (obj->id == GRASS_OBJ) {
        grass_t *grass = obj->data;
        sfFloatRect rect_grass =
            sfSprite_getGlobalBounds(grass->sprite);
        if (sfFloatRect_intersects(&rect_entity, &rect_grass, NULL))
            return 1;
    }
    return 0;
}

void collisions_with_sword(game_t *game, object_t *obj, item_t *sword)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    if (obj->id == ENEMY_OBJ && handle_enemies_collisions(obj, sword->entity,
            game) && !CAST_ENEMY(obj->data)->is_hit) {
            hit_enemy(CAST_ENEMY(obj->data), player->attack, game);
            set_pos_hit(game, CAST_ENEMY(obj->data)->self_pos);
            sword->hit_effect = 1;
    }
    if (obj->id == GRASS_OBJ && handle_grass_collisions(obj,
        sword->entity, game, (sfVector2f){0, 0}))
            ((grass_t *)obj->data)->is_hit = 1;
}
