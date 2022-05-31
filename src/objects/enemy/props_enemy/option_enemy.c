/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** option_enemy
*/

#include "option.h"
#include "object.h"

option_t blob_option(void)
{
    option_t option;
    option.path = BLOB_PATH;
    option.scale = (sfVector2f){1, 1};
    option.int_rect = (sfIntRect){0, 0, 28, 20};
    option.rect_x = 28;
    option.rect_y = 20;
    option.spritesheet_width = 84;
    option.spritesheet_height = 40;
    return option;
}

option_t slime_option(void)
{
    option_t option;
    option.path = SLIME_PATH;
    option.scale = (sfVector2f){1, 1};
    option.int_rect = (sfIntRect){0, 0, 12, 12};
    option.rect_x = 12;
    option.rect_y = 12;
    option.spritesheet_width = 36;
    option.spritesheet_height = 24;
    return option;
}

option_t ghost_option(void)
{
    option_t option;
    option.path = GHOST_PATH;
    option.scale = (sfVector2f){1, 1};
    option.int_rect = (sfIntRect){0, 0, 20, 18};
    option.rect_x = 20;
    option.rect_y = 18;
    option.spritesheet_width = 80;
    option.spritesheet_height = 36;
    return option;
}

option_t skeleton_option(void)
{
    option_t option;
    option.path = SKELETON_PATH;
    option.scale = (sfVector2f){1, 1};
    option.int_rect = (sfIntRect){0, 0, 15, 15};
    option.rect_x = 15;
    option.rect_y = 15;
    option.spritesheet_width = 45;
    option.spritesheet_height = 30;
    return option;
}
