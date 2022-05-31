/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

void exit_game(game_t *game);
void set_game_scene(game_t *game);
void set_settings_scene(game_t *game);
void set_menu_scene(game_t *game);
button_t *init_button(sfIntRect rect, sfVector2f pos_btn,
                    void (*ptr_btn)(game_t *), int id);
void draw_buttons_start(game_t *game, object_t *button);
void handle_button_event_start(game_t *game, object_t *button);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
                        void (*draw)());
void set_pause_scene(game_t *game);
void return_to_previous_scene(game_t *game);
void set_help_scene(game_t *game);
void reset_settings(game_t *game);
void increase_general_volume(game_t *game);
void decrease_general_volume(game_t *game);
void increase_music_volume(game_t *game);
void decrease_music_volume(game_t *game);
void reset_game(game_t *game);

static sfIntRect (rect_sprite[]) = {
    {0, 0, 86, 25}, //continue 0
    {86, 0, 86, 25}, //start 1
    {172, 0, 86, 25}, //exit 2
    {258, 0, 86, 25}, //settings 3
    {344, 0, 86, 25}, //quit 4
    {0, 25, 60, 25}, //reset 5
    {60, 25, 60, 25}, //back 6
    {0, 50, 20, 25}, //? 7
    {20, 50, 20, 25}, //+ 8
    {40, 50, 20, 25}, //- 9
    {0, 75, 168, 25} //retry 10
};

static void (*ptr_btn[])(game_t *) = {
    &set_game_scene, //0
    &set_settings_scene, //1
    &exit_game, //2
    &set_help_scene, //3
    &increase_general_volume, //4
    &increase_music_volume, //5
    &reset_settings, //6
    &return_to_previous_scene, //7
    &set_menu_scene, //8
    &decrease_general_volume, //9
    &decrease_music_volume, //10
    &reset_game //11
};

static void (*ptr_handler[])(game_t *, object_t *) = {
    &handle_button_event_start,
    &handle_button_event_start,
    &handle_button_event_start,
    &handle_button_event_start,
    &handle_button_event_start,
    &handle_button_event_start,
    &handle_button_event_start
};

static void (*ptr_draw[])(game_t *, object_t *) = {
    &draw_buttons_start,
    &draw_buttons_start,
    &draw_buttons_start,
    &draw_buttons_start,
    &draw_buttons_start,
    &draw_buttons_start,
    &draw_buttons_start
};

void parse_button(game_t *game, char **args, int id, int scene)
{
    int argc = 0;
    int btn_id = -1;
    int ptr = -1;

    for (; args[argc] != NULL; ++argc);
    if (argc != NB_ARGS_BUTTON)
        return;
    btn_id = my_getnbr(args[1]);
    ptr = my_getnbr(args[4]);
    if (btn_id < 0 || btn_id > NB_BUTTONS || ptr < 0 ||
        ptr >= NB_PTR_ID)
        return;
    button_t *button = init_button(rect_sprite[btn_id],
                                    (sfVector2f){(float)my_getnbr(args[2]),
                                    (float)my_getnbr(args[3])},
                                    ptr_btn[ptr], btn_id);
    if (button == NULL)
        return;
    object_t *object = create_object(0, button,
            ptr_handler[game->current_scene], ptr_draw[game->current_scene]);
    my_put_in_list(&game->scene[scene]->obj, object);
}
