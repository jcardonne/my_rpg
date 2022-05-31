/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-dante-selim-han.kirac
** File description:
** main.c
*/

#include "my.h"
#include "rpg.h"
#include "settings.h"

sfText *init_clock_object_text(game_t *game);
void init_inventory_menu(game_t *game);
void init_settings_menu(game_t *game);
void init_pause_menu(game_t *game);
void init_start_menu(game_t *game);
void set_menu_scene(game_t *game);
void set_game_scene(game_t *game);
void inventory_menu(game_t *game);
void init_help_menu(game_t *game);
void settings_menu(game_t *game);
void start_menu(game_t *game);
void pause_menu(game_t *game);
void save_score(game_t *game);
void init_game(game_t *game);
void help_menu(game_t *game);
void init_data(game_t *data);
void game(game_t *game);
void print_help(void);
void death_scene(game_t *game);
void init_death_menu(game_t *game);
void init_end_blob(game_t *game);
void end_blob(game_t *game);

void (* const scene[])(game_t *game) = {
        &start_menu,
        &game,
        &settings_menu,
        &pause_menu,
        &help_menu,
        &inventory_menu,
        &death_scene,
        &end_blob
};

static void start_game(game_t *game)
{
    init_start_menu(game);
    init_pause_menu(game);
    init_inventory_menu(game);
    init_settings_menu(game);
    init_death_menu(game);
    init_help_menu(game);
    init_game(game);
    init_end_blob(game);
    set_menu_scene(game);
    while (sfRenderWindow_isOpen(game->window)) {
        scene[game->current_scene](game);
    }
}

void arg_handler(int argc, char **argv, game_t *game)
{
    for (int i = 1; i < argc; ++i)
        if (my_strcmp(argv[i], "-d") == 0 || my_strcmp(argv[i], "--debug"))
            game->debug_mode = true;
}

int main(int argc, char **argv)
{
    game_t game;

    if (argc >= 2 && !my_strcmp(argv[1], "-h"))
        print_help();
    init_data(&game);
    arg_handler(argc, argv, &game);
    start_game(&game);
    save_score(&game);
    return (0);
}
