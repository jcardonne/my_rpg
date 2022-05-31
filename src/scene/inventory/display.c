/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "my.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);

void update_texts(game_t *game)
{
    sfText_setString(
        CAST_PLAYER(game->play->player->data)->inventory.health_text,
        my_int_to_strnum(CAST_PLAYER(game->play->player->data)->health));
    sfText_setString(
        CAST_PLAYER(game->play->player->data)->inventory.attack_text,
        my_int_to_strnum(CAST_PLAYER(game->play->player->data)->attack));
}

void draw_background(game_t *game)
{
    sfSprite *sprite_background = sfSprite_create();
    sfSprite *sprite_background_ui = sfSprite_create();
    sfTexture *texture = NULL;
    texture =
            sfTexture_createFromFile("assets/images/inventory_ui.png", NULL);
    sfSprite_setTexture(sprite_background_ui, texture, sfFalse);
    sfSprite_setTexture(sprite_background,
                        game->scene[INVENTORY_SCENE]->texture_background_saved,
                        sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite_background, NULL);
    sfRenderWindow_drawSprite(game->window, sprite_background_ui, NULL);
}

void draw_stats(game_t *game)
{
    inventory_t *inventory =
        &((player_t *)(game->play->player->data))->inventory;

    update_texts(game);
    sfRenderWindow_drawText(game->window, inventory->attack_text, NULL);
    sfRenderWindow_drawText(game->window, inventory->health_text, NULL);
}

void draw_items(game_t *game)
{
    object_t *object = NULL;
    item_t *item = NULL;
    inventory_t inventory = CAST_PLAYER(game->play->player->data)->inventory;
    sfVector2f pos = {700, 680};
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        object = inventory.items[i];
        if (object != NULL && object->data != NULL) {
            item = object->data;
            sfSprite_setScale(item->entity->sprite, (sfVector2f){3.0, 3.0});
            sfSprite_setPosition(item->entity->sprite, pos);
            sfSprite_setRotation(item->entity->sprite, 180.0);
            draw_entity(game, item->entity);
        }
        pos.x += 38.0 * 3.0 + 22.5;
        if (i == INVENTORY_SIZE / 2 - 1) {
            pos.y += 45.0 * 3.0 + 10.0;
            pos.x = 700;
        }
    }
}

void draw_following_item(game_t *game)
{
    cursor_t *cursor = game->cursor;
    if (cursor->item_selected_index == -1)
        return;
    sfVector2f pos = cursor->pos;
    item_t *item = CAST_PLAYER(game->play->player->data)->inventory.items
        [cursor->item_selected_index]->data;
    sfSprite_setPosition(item->entity->sprite, pos);
    draw_entity(game, item->entity);
}
