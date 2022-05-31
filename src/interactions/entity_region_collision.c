/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** player_region_collision
*/

#include "game.h"
#include "region.h"
#include <stdio.h>
#include <stdbool.h>

void change_region(game_t *game, region_t *current_region, int dir_x,
int dir_y);

static bool is_pixel_red(sfImage *image, int x, int y)
{
    sfColor color = sfImage_getPixel(image, x, y);

    return (color.r == 255 && color.g == 0 && color.b == 0);
}

bool is_pixel_colliding(game_t *game, sfFloatRect *player_bounds, int y)
{
    for (int x = player_bounds->left; x < player_bounds->width
        + player_bounds->left; ++x) {
        if (is_pixel_red(game->play->current_region->map->collision, x, y)) {
            return true;
        }
    }
    return false;
}

void move_to_region(game_t *game, sfFloatRect *player_bounds)
{
    if (player_bounds->top + player_bounds->height / 2
        < game->play->current_region_pos.y * REGION_SIZE_Y
        && game->play->current_region->top != NULL)
            change_region(game, game->play->current_region->top, 0, -1);
    if (player_bounds->top + player_bounds->height / 2
        > (game->play->current_region_pos.y + 1) * REGION_SIZE_Y
        && game->play->current_region->bottom != NULL)
            change_region(game, game->play->current_region->bottom, 0, 1);
    if (player_bounds->left + player_bounds->width / 2
        < game->play->current_region_pos.x * REGION_SIZE_X
        && game->play->current_region->left != NULL)
            change_region(game, game->play->current_region->left, -1, 0);
    if (player_bounds->left + player_bounds->width / 2
        > (game->play->current_region_pos.x + 1) * REGION_SIZE_X
        && game->play->current_region->right != NULL)
            change_region(game, game->play->current_region->right, 1, 0);
}

bool check_region_bound(game_t *game, sfFloatRect *player_bounds)
{
    return ((player_bounds->top
        < game->play->current_region_pos.y * REGION_SIZE_Y
        && game->play->current_region->top == NULL)
        || (player_bounds->top + player_bounds->height
        > (game->play->current_region_pos.y + 1) * REGION_SIZE_Y
        && game->play->current_region->bottom == NULL)
        || (player_bounds->left
        < game->play->current_region_pos.x * REGION_SIZE_X
        && game->play->current_region->left == NULL)
        || (player_bounds->left + player_bounds->width
        > (game->play->current_region_pos.x + 1) * REGION_SIZE_X
        && game->play->current_region->right == NULL));
}

bool check_entity_region_collision(game_t *game, sfVector2f shift,
                                    entity_t entity, int is_player)
{
    sfFloatRect entity_bounds = sfSprite_getGlobalBounds(entity.sprite);
    entity_bounds.left += shift.x;
    entity_bounds.top += shift.y;

    if (check_region_bound(game, &entity_bounds))
        return true;
    for (int y = entity_bounds.top; y < entity_bounds.height
        + entity_bounds.top; ++y)
        if (is_pixel_colliding(game, &entity_bounds, y))
            return true;
    if (is_player)
        move_to_region(game, &entity_bounds);
    return false;
}
