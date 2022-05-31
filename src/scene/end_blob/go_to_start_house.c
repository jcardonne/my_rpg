/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** go_to_start_house.c
*/

#include "rpg.h"

void set_game_scene(game_t *game);
void change_region(game_t *game, region_t *new_region, int dir_x, int dir_y);

void go_to_house_start(game_t *game)
{
    game->play->current_region = game->play->start_region;
    game->play->current_region_pos.x = START_REGION_X;
    game->play->current_region_pos.y = START_REGION_Y;
    game->game_end = 1;
    game->play->view = NULL;
    player_t *player = CAST_PLAYER(game->play->player->data);
    set_game_scene(game);
    change_region(game, game->play->start_region, 0, 0);
    sfSprite_setPosition(player->entity.sprite, (sfVector2f){REGION_SIZE_X *
    game->play->current_region_pos.x +240, REGION_SIZE_Y * game->play->
    current_region_pos.y + 130});
    sfSprite_setTextureRect(player->entity.sprite, (sfIntRect){0, 0, 16, 16});
}