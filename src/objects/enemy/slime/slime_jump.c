/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** slime_jump.c
*/

#include "rpg.h"
#include "object.h"
#include <math.h>

sfVector2f normalize_vector(sfVector2f vector);
sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2);
int check_collision(game_t *game, entity_t entity, sfVector2f shift, int dead);
sfVector2f get_pos_player(game_t *game);
sfVector2f get_pos_player_projected(game_t *game);
sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate);

static sfVector2f get_destination_3d(game_t *game, enemy_t *slime)
{
    sfVector2f destination;
    sfVector2f direction3d;
    sfVector2f self_pos_3d = project_iso_point((sfVector3f){slime->self_pos.x,
                                                slime->self_pos.y, 0},
                                                (sfVector2i){0, 0});
    if (slime->trigerred) {
        destination = get_pos_player_projected(game);
        direction3d = normalize_vector(calc_new_vector(self_pos_3d,
                                                        destination));
    } else {
        destination = project_iso_point((sfVector3f)
                                        {slime->pos[slime->where_to_go].x,
                                        slime->pos[slime->where_to_go].y, 0},
                                        (sfVector2i){0, -80});
        direction3d = normalize_vector(calc_new_vector(self_pos_3d,
                                                        destination));
    }
    return direction3d;
}

void slime_jump(game_t *game, enemy_t *slime)
{
    if (slime->animation_data.distance_jumped <
                                        slime->animation_data.jump_height / 2)
        slime->coords_3d.z++;
    else
        slime->coords_3d.z--;
    slime->self_pos = project_iso_point(slime->coords_3d, slime->translation);
    slime->direction_3d = get_destination_3d(game, slime);
    if (check_collision(game, slime->entity, slime->direction,
        slime->animation_data.animate_death) || slime->bouncing) {
        slime->direction.x *= -1;
        slime->direction.y *= -1;
        slime->bouncing = 1;
    }
    slime->coords_3d.x += slime->direction.x;
    slime->coords_3d.y += slime->direction.y;
    sfSprite_setPosition(slime->entity.sprite, slime->self_pos);
}
