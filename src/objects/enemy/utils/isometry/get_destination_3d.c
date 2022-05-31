/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** get_destination_3d.c
*/

#include "rpg.h"

sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate);
sfVector2f get_pos_player_projected(game_t *game);
sfVector2f normalize_vector(sfVector2f vector);
sfVector2f calc_new_vector(sfVector2f point1, sfVector2f point2);

sfVector2f get_destination_3d(game_t *game, enemy_t *enemy)
{
    sfVector2f destination;
    sfVector2f direction3d;
    sfVector2f self_pos_3d = project_iso_point((sfVector3f){enemy->self_pos.x,
                                                enemy->self_pos.y, 0},
                                                enemy->translation);
    if (enemy->trigerred) {
        destination = get_pos_player_projected(game);
        direction3d = normalize_vector(calc_new_vector(self_pos_3d,
                                                        destination));
    } else {
        destination = project_iso_point((sfVector3f)
                                        {enemy->pos[enemy->where_to_go].x,
                                        enemy->pos[enemy->where_to_go].y, 0},
                                        enemy->translation);
        direction3d = normalize_vector(calc_new_vector(self_pos_3d,
                                                        destination));
    }
    return direction3d;
}
