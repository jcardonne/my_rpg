/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** get_pos_player_projected.c
*/

#include "rpg.h"

sfVector2f get_pos_player(game_t *game);
sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate);
sfVector2i create_translation(sfVector2f pos);

sfVector2f get_pos_player_projected(game_t *game)
{
    sfVector3f player_3d;
    sfVector2f output;
    sfVector2f pos_player = get_pos_player(game);
    sfVector2i translation = create_translation(pos_player);
    player_3d.x = pos_player.x;
    player_3d.y = pos_player.y;
    player_3d.z = 0;
    output = project_iso_point(player_3d, translation);
    return output;
}
