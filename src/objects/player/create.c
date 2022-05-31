/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

void handler_player(game_t *game);
void draw_player(game_t *game);

static entity_t create_player_entity(option_t option)
{
    entity_t entity;
    entity.sprite = sfSprite_create();
    entity.texture = sfTexture_createFromFile(option.path, NULL);
    entity.spritesheet_width = option.spritesheet_width;
    entity.spritesheet_height = option.spritesheet_height;
    sfSprite_setTexture(entity.sprite, entity.texture, sfTrue);
    sfSprite_setScale(entity.sprite, option.scale);
    sfSprite_setPosition(entity.sprite, option.pos);
    entity.rect = option.int_rect;
    sfSprite_setTextureRect(entity.sprite, entity.rect);
    entity.spritesheet_rect_x = 16;
    entity.spritesheet_rect_y = 16;
    entity.animation_state = IDLE_STATE;
    sfSprite_setOrigin(entity.sprite, (sfVector2f){8, 8});
    return entity;
}

object_t *create_player_object(option_t option)
{
    player_t *player = malloc(sizeof(player_t));
    object_t *object = malloc(sizeof(object_t));

    player->speed = 150;
    player->health = 3;
    player->attack = 1;
    player->hit_delay = 0;
    player->orientation = 0;
    player->is_hit = 0;
    player->emitters = NULL;
    player->entity = create_player_entity(option);
    object->data = player;
    object->handler = &handler_player;
    object->draw = &draw_player;
    return (object);
}
