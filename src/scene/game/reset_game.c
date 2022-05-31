/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** reset_game.c
*/

#include "rpg.h"

void set_game_scene(game_t *game);
void load_region(game_t *game, region_t *region);
void change_region(game_t *game, region_t *current_region,
int dir_x, int dir_y);
void restart_clock(game_t *game, clock_object_t *clock);

static void find_and_restard_clock(game_t *game)
{
    linked_list_t *tmp = game->scene[GAME_SCENE]->obj;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        if (obj->id == CLOCK_OBJ) {
            restart_clock(game, (clock_object_t *)obj->data);
            return;
        }
        tmp = tmp->next;
    }
}

static void reset_values(game_t *game)
{
    CAST_PLAYER(game->play->player->data)->emitters = NULL;
    CAST_PLAYER(game->play->player->data)->health = 3;
    game->play->stats.nb_killed_slimes = 0;
    game->play->current_region_pos.x = START_REGION_X;
    game->play->current_region_pos.y = START_REGION_Y;
}

void reset_game(game_t *game)
{
    find_and_restard_clock(game);
    for (int i = 0; i < REGION_NB; ++i) {
        game->play->region_list[i]->is_loaded = 0;
        game->play->region_list[i]->objects = NULL;
        game->play->region_list[i]->music_path = NULL;
    }
    reset_values(game);
    sfSprite_setPosition(CAST_PLAYER(game->play->player->data)->entity.sprite,
        (sfVector2f){REGION_SIZE_X * game->play->current_region_pos.x +
        240, REGION_SIZE_Y * game->play->current_region_pos.y + 130});
    game->play->current_region = NULL;
    change_region(game, game->play->start_region, 0, 0);
    sfView_setCenter(game->play->view, (sfVector2f){START_REGION_X *
        REGION_SIZE_X + REGION_SIZE_X / 2,
        START_REGION_Y * REGION_SIZE_Y + REGION_SIZE_Y / 2});
    sfRenderWindow_setView(game->window, game->play->view);
    if (game->current_scene == DEATH_SCENE)
        set_game_scene(game);
}
