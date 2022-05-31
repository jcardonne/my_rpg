/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

void init_all_maps(game_t *game);
particles_emitter_t *init_emitter(void);
object_t *create_player_object(option_t option);
object_t *init_clock_object_text(game_t *game);
object_t *init_background_ui_object(game_t *game);
object_t *init_hearts_ui_object(game_t *game);
void init_inventory(game_t *game);

static void init_game_scene_objects(game_t *game)
{
    option_t option = {
        "./assets/spritesheets/character.png",
        (sfVector2f){1.0, 1.0},
        (sfVector2f){REGION_SIZE_X * game->play->current_region_pos.x +
        240, REGION_SIZE_Y * game->play->current_region_pos.y + 130},
        (sfIntRect){0, 0, 16, 16},
        16, 16, 96, 96,
    };
    game->play->player = create_player_object(option);
    init_inventory(game);
    my_put_in_list(&game->scene[GAME_SCENE]->obj, init_hearts_ui_object(game));
    my_put_in_list(&game->scene[GAME_SCENE]->obj,
                    init_clock_object_text(game));
    my_put_in_list(&game->scene[GAME_SCENE]->obj,
                    init_background_ui_object(game));
}

void init_game(game_t *game)
{
    game->play = malloc(sizeof(play_t));
    game->play->current_region = NULL;
    game->play->view = NULL;
    init_all_maps(game);
    init_all_regions(game);
    game->scene[GAME_SCENE] = malloc(sizeof(scene_t));
    game->scene[GAME_SCENE]->nb_buttons = 0;
    game->scene[GAME_SCENE]->obj = NULL;
    game->scene[GAME_SCENE]->emitter = init_emitter();
    game->scene[GAME_SCENE]->texture_background_saved = NULL;
    init_game_scene_objects(game);
    game->play->region_animation.changing = false;
    game->play->stats.nb_killed_slimes = 0;
}
