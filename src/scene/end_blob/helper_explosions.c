/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** helper_explosions.c
*/

#include "rpg.h"

explosion_t init_explo(int x, int y, sfTexture *texture, long current_us)
{
    explosion_t explosions;
    sfVector2f pos = {x, y};
    explosions.activated = 0;
    explosions.done = 0;
    explosions.loaded = 1;
    explosions.last_animation = current_us;
    explosions.offset_x = 0;
    explosions.sprite = sfSprite_create();
    sfSprite_setTexture(explosions.sprite, texture, sfFalse);
    sfSprite_setScale(explosions.sprite, (sfVector2f){7, 7});
    sfSprite_setPosition(explosions.sprite, pos);
    sfSprite_setTextureRect(explosions.sprite,
                        (sfIntRect){explosions.offset_x, 0, 29, 18});
    return explosions;
}

// void handle_conditions(explosion_t *explosions, double diff, )
// {
//     if (diff >= delay[i] && !explosions[i].activated &&
//         !explosions[i].done && !already_activated) {
//         explosions[i].activated = 1;
//         explosions[i].last_animation = current_us;
//         already_activated = 1;
//     }
//     if (diff >= 0.1 && explosions[i].activated) {
//         explosions[i].offset_x += 29;
//         explosions[i].last_animation = current_us;
//     }
//     if (explosions[i].offset_x >= 145) {
//         explosions[i].done = 1;
//         explosions[i].activated = 0;
//     }
// }