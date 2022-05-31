/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** check_collision.c
*/

#include "rpg.h"
#include "object.h"

bool check_entity_region_collision(game_t *game, sfVector2f shift,
                                    entity_t entity, int is_player);
particles_emitter_t *init_emitter(void);
sfVector2f get_pos_player(game_t *game);
void player_hit(game_t *game, player_t *player);

int check_player_collision(game_t *game, sfVector2f shift, entity_t entity)
{
    sfFloatRect player_bound = sfSprite_getGlobalBounds(CAST_PLAYER
                                                        (game->play->player->
                                                        data)->entity.sprite);
    sfFloatRect entity_bound = sfSprite_getGlobalBounds(entity.sprite);
    if (sfFloatRect_intersects(&player_bound, &entity_bound, NULL)
            == sfTrue) {
        if (!CAST_PLAYER(game->play->player->data)->is_hit)
            player_hit(game, CAST_PLAYER(game->play->player->data));
        return 1;
    }
    return 0;
}

int check_collision(game_t *game, entity_t entity, sfVector2f shift, int dead)
{
    if (check_entity_region_collision(game, shift, entity, 0) == true)
        return 1;
    if (!dead && check_player_collision(game, shift, entity))
        return 1;
    return 0;
}
