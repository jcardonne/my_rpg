/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"

sfVector2f get_pos_player(game_t *game);
void add_item(game_t *game, object_t *item);

sfVector2f get_position_interaction(player_t *player, int status)
{
    sfVector2f pos = sfSprite_getPosition(player->entity.sprite);

    if (status == RIGHT) {
        pos.x += 19.0;
        pos.y -= 2.5;
    }
    if (status == LEFT) {
        pos.x -= 19.5;
        pos.y += 8.0;
    }
    if (status == DOWN) {
        pos.x += 10.0;
        pos.y += 17.0;
    }
    if (status == UP) {
        pos.x += 2.0;
        pos.y -= 14.0;
    }
    return pos;
}

void handle_item(game_t *game, object_t *self)
{
    item_t *item = self->data;
    sfFloatRect rect_item = sfSprite_getGlobalBounds(item->entity->sprite);
    sfVector2f pos_player = get_pos_player(game);

    if (!item->on_the_ground)
        return;
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        sfFloatRect_contains(&rect_item,
        pos_player.x, pos_player.y) == sfTrue) {
            add_item(game, self);
            item->unlocked = 1;
            item->on_the_ground = 0;
        }
}
