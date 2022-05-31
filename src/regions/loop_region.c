/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** loop_region
*/

#include "rpg.h"
#include "region.h"
#include "game.h"
#include "object.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);
item_t *get_selected_item(game_t *game);

static void handle_emitters(player_t *player, game_t *game)
{
    linked_list_t *tmp = player->emitters;

    while (tmp != NULL) {
        particles_emitter_t *emitter = tmp->data;
        emitter->ptr_part(emitter, BLOOD, emitter->pos, game->window);
        tmp = tmp->next;
    }
}

void draw_region_objects(game_t *game, region_t *region)
{
    object_t *obj;

    for (linked_list_t *head = region->objects; head;
        head = head->next) {
        obj = head->data;
        obj->draw(game, obj);
    }
}

void draw_debug_mode(game_t *game, region_t *region)
{
    if (!game->debug_mode)
        return;
    static sfSprite *collision = NULL;
    static region_t *region_old = NULL;
    if (collision == NULL || region_old != region) {
        region_old = region;
        collision = sfSprite_create();
        sfSprite_setTexture(collision, sfTexture_createFromImage(
            region->map->collision, NULL), false);
        sfSprite_setColor(collision, (sfColor){255, 255, 255, 100});
    }
    sfRenderWindow_drawSprite(game->window, collision, NULL);
}

void draw_region(game_t *game, region_t *region)
{
    sfRenderWindow_drawSprite(game->window, region->map->background, NULL);
    handle_emitters(CAST_PLAYER(game->play->player->data), game);
    draw_region_objects(game, region);
    game->play->player->draw(game, game->play->player);
    item_t *held = get_selected_item(game);
    if (held != NULL && held->handle_hit != NULL)
        held->handle_hit(game, held);
    sfRenderWindow_drawSprite(game->window, region->map->foreground, NULL);
    draw_debug_mode(game, region);
    draw_scene(game);
}

void handle_region(game_t *game)
{
    handle_object(game);
    object_t *obj;
    for (linked_list_t *head = game->play->current_region->objects; head;
        head = head->next) {
        obj = head->data;
        obj->handler(game, obj);
    }
    if (!game->game_end)
        game->play->player->handler(game, game->play->player);
}
