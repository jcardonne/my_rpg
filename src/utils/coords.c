/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** coords
*/

#include "rpg.h"

sfVector2f move_coords(sfVector2f pos, float x, float y)
{
    sfVector2f result = pos;

    result.x += x;
    result.y += y;
    return (result);
}
