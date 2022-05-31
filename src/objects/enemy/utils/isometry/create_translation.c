/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create_translation.c
*/

#include "rpg.h"

sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate);

sfVector2i create_translation(sfVector2f pos)
{
    sfVector3f coords_3d = {pos.x, pos.y, 0};
    sfVector2f projection = project_iso_point(coords_3d, (sfVector2i){0, 0});
    sfVector2i translation = {pos.x - projection.x, pos.y - projection.y};
    return translation;
}
