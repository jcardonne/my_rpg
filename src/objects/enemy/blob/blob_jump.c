/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** blob_jump.c
*/

#include "rpg.h"

sfVector2f normalize_vector(sfVector2f vector);
sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2);
int check_collision(game_t *game, entity_t entity, sfVector2f shift, int dead);
sfVector2f get_pos_player(game_t *game);
sfVector2f get_pos_player_projected(game_t *game);
sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate);

static sfVector2f get_destination_3d(game_t *game, enemy_t *blob)
{
    sfVector2f destination;
    sfVector2f direction3d;
    sfVector2f self_pos_3d = project_iso_point((sfVector3f){blob->self_pos.x,
                                                blob->self_pos.y, 0},
                                                (sfVector2i){0, 0});
    destination = get_pos_player_projected(game);
    direction3d = normalize_vector(calc_new_vector(self_pos_3d,
                                                    destination));
    return direction3d;
}

void blob_jump(game_t *game, enemy_t *blob)
{
    if (blob->animation_data.distance_jumped <
                                        blob->animation_data.jump_height / 2)
        blob->coords_3d.z++;
    else
        blob->coords_3d.z--;
    blob->self_pos = project_iso_point(blob->coords_3d, blob->translation);
    blob->direction_3d = get_destination_3d(game, blob);
    if (check_collision(game, blob->entity, blob->direction,
        blob->animation_data.animate_death) || blob->bouncing) {
        blob->direction.x *= -1;
        blob->direction.y *= -1;
        blob->bouncing = 1;
    }
    blob->coords_3d.x += blob->direction.x;
    blob->coords_3d.y += blob->direction.y;
    sfSprite_setPosition(blob->entity.sprite, blob->self_pos);
}
