/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** project_iso_point.c
*/

#include "rpg.h"
#include <math.h>

sfVector2f project_iso_point(sfVector3f coords_3d, sfVector2i translate)
{
    sfVector2f vector;
    float angle_x = DEG_TO_RAD(35);
    float angle_y = DEG_TO_RAD(25);
    vector.x = (cos(angle_x) * coords_3d.x - cos(angle_x) * coords_3d.y) +
                translate.x;
    vector.y = (sin(angle_y) * coords_3d.y + sin(angle_y) * coords_3d.x -
                coords_3d.z) + translate.y;
    return vector;
}
