/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** entity
*/

#include "rpg.h"

void draw_entity(game_t *game, entity_t *entity)
{
    sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){61, 70, 242, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){61, 70, 242, 200});
    }
    sfFloatRect rect = sfSprite_getGlobalBounds(entity->sprite);
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width,
        rect.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left,
        rect.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}

void draw_list_entity(game_t *game, linked_list_t **list)
{
    linked_list_t *tmp = *list;

    while (tmp != NULL) {
        draw_entity(game, &((player_t *)(tmp->data))->entity);
        tmp = tmp->next;
    }
}
