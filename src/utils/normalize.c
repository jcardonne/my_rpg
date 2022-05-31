/*
** EPITECH PROJECT, 2022
** myrpg [WSL: Ubuntu]
** File description:
** normalize
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>

sfVector2f normalize_vector(sfVector2f vector)
{
    float norm = sqrtf(vector.x * vector.x + vector.y * vector.y);

    vector.x = vector.x / norm;
    vector.y = vector.y / norm;
    return (vector);
}
