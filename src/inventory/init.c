/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** inventory.c
*/

#include "rpg.h"
#include "my.h"

void get_save(game_t *game);

void init_texts(game_t *game)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t *inventory = &player->inventory;

    sfVector2f pos = {1185.0, 400.0};
    sfVector2f pos_two = {690.0, 400.0};

    inventory->attack_text = sfText_create();
    sfText_setFont(inventory->attack_text, game->data.retro_font);
    sfText_setScale(inventory->attack_text, (sfVector2f){1.2, 1.2});
    sfText_setFillColor(inventory->attack_text, sfWhite);
    sfText_setPosition(inventory->attack_text, pos);
    sfText_setString(inventory->attack_text, my_int_to_strnum(player->attack));
    inventory->health_text = sfText_create();
    sfText_setFont(inventory->health_text, game->data.retro_font);
    sfText_setScale(inventory->health_text, (sfVector2f){1.2, 1.2});
    sfText_setFillColor(inventory->health_text, sfWhite);
    sfText_setPosition(inventory->health_text, pos_two);
    sfText_setString(inventory->health_text, my_int_to_strnum(player->health));
}

void init_inventory(game_t *game)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        player->inventory.items[i] = NULL;
    }
    player->inventory.nb_items = 0;
    init_texts(game);
    get_save(game);
}
