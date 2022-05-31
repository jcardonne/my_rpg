/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** events_handler.c
*/

#include "rpg.h"
#include "my.h"

void check_mouse_movement(game_t *game);
void set_game_scene(game_t *game);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
void exit_game(game_t *game);
void drag_drop_intention(game_t *game, inventory_t *inventory);
void drag_drop_deplacement(game_t *game, inventory_t *inventory);
item_t *get_selected_item(game_t *game);

static void update_status(game_t *game)
{
    item_t *held = get_selected_item(game);
    if (held != NULL)
        CAST_PLAYER(game->play->player->data)->attack = held->attack_value;
    else
        CAST_PLAYER(game->play->player->data)->attack = 1;
}

void events_handler_inventory_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            exit_game(game);
        check_mouse_movement(game);
        if (game->event.type == sfEvtKeyReleased &&
            (game->event.key.code == sfKeyI ||
                game->event.key.code == sfKeyEscape))
            set_game_scene(game);
        if (game->event.type == sfEvtMouseButtonPressed &&
            game->event.mouseButton.button == sfMouseLeft)
            drag_drop_intention(game,
                &CAST_PLAYER(game->play->player->data)->inventory);
        if (game->event.type == sfEvtMouseButtonReleased &&
            game->event.mouseButton.button == sfMouseLeft)
            drag_drop_deplacement(game,
                &CAST_PLAYER(game->play->player->data)->inventory);
    }
    update_status(game);
}
