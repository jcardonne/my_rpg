/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include <stdio.h>

int get_random_seed(void);
explosion_t init_explo(int x, int y, sfTexture *texture, long current_us);
int draw_background_end_blob(game_t *game);
void set_game_scene(game_t *game);
void change_region(game_t *game, region_t *new_region, int dir_x, int dir_y);
void go_to_house_start(game_t *game);

static explosion_t explosions[40];

const static float delay[40] = {
    0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5,
    1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
    3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0
};

void events_handler_end_blob(game_t *game);

static void init_explosions(game_t *game, sfTexture *texture)
{
    if (explosions[0].loaded)
        return;
    srand(get_random_seed());
    texture = sfTexture_createFromFile("assets/spritesheets/explosion.png",
                NULL);
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    for (int i = 0; i < 40; ++i) {
        if (explosions[i].activated)
            continue;
        int rand_x = rand() % 1000 + 200;
        int rand_y = rand() % 500 + 100;
        explosions[i] = init_explo(rand_x, rand_y, texture, current_us);
    }
}

static void handle_condition(int i, int *activated,
                            double diff, double current_us)
{
    if (diff >= delay[i] && !explosions[i].activated &&
        !explosions[i].done && *activated == 0) {
        explosions[i].activated = 1;
        explosions[i].last_animation = current_us;
        *activated = 1;
    }
    if (diff >= 0.1 && explosions[i].activated) {
        explosions[i].offset_x += 29;
        explosions[i].last_animation = current_us;
    }
    if (explosions[i].offset_x >= 145) {
        explosions[i].done = 1;
        explosions[i].activated = 0;
    }
}

static void handle_explosions(game_t *game)
{
    static sfTexture *texture = NULL;
    int already_activated = 0;
    static int nb_explosions = 0;
    if (texture == NULL)
        init_explosions(game, texture);
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    for (int i = 0; i < 40; ++i) {
        double diff = (current_us - explosions[i].last_animation) / 1000000.0;
        handle_condition(i, &already_activated, diff, current_us);
    }
}

static void draw_explosions(game_t *game)
{
    for (int i = 0; i < 40; ++i) {
        if (explosions[i].activated) {
            sfSprite_setTextureRect(explosions[i].sprite,
                (sfIntRect){explosions[i].offset_x, 0, 29, 18});
            sfRenderWindow_drawSprite(game->window, explosions[i].sprite,
                                        NULL);
        }
    }
}

void end_blob(game_t *game)
{
    sfRenderWindow_clear(game->window, sfWhite);
    events_handler_end_blob(game);
    handle_explosions(game);
    if (game->current_scene != END_SCENE_BLOB)
        return;
    if (!draw_background_end_blob(game)) {
        go_to_house_start(game);
        return;
    }
    draw_explosions(game);
    sfRenderWindow_display(game->window);
}