/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"
#include "npc.h"
#include "my.h"
#include "dialogue.h"

dialogue_box_t *create_dialogue_data(game_t *game);
void draw_npc_start_dog(game_t *game, object_t *self);
void npc_start_dog_handler(game_t *game, object_t *self);
int parse_dialogue_file(game_t *game, npc_t *npc);

static void init_npc_start_dog_entity(npc_t *npc, entity_t *entity)
{
    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(DOG_PATH, NULL);
    entity->rect = (sfIntRect){0, 0, 16, 16};
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setPosition(entity->sprite, npc->start_pos);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setOrigin(entity->sprite, (sfVector2f){entity->rect.width / 2,
        entity->rect.height / 2});
    entity->animation_state = IDLE_STATE;
    entity->spritesheet_rect_x = 0;
    entity->spritesheet_rect_y = 16;
    entity->spritesheet_width = 16;
    entity->spritesheet_height = 16;
}

static void init_npc_start_dog_dialogue(npc_t *npc, dialogue_box_t *dialogue)
{
    dialogue->pos.x = npc->start_pos.x;
    dialogue->pos.y = npc->start_pos.y - npc->entity.spritesheet_rect_y;
    dialogue->content = "IL MANQUE LE FICHIER DE DIALOGUE";
    dialogue->content_stripped = my_strdup(dialogue->content);
    dialogue->max_index = my_strlen(dialogue->content);
    dialogue->delay = 0.03;
    npc->dialogue_index = 0;
    npc->dialogue_line = 0;
    npc->dialogue_nb = 0;
    npc->is_talking = false;
}

void create_npc_dog(game_t *game, object_t *self)
{
    npc_t *npc = self->data;
    npc->dialogue = create_dialogue_data(game);
    init_npc_start_dog_entity(npc, &npc->entity);
    init_npc_start_dog_dialogue(npc, npc->dialogue);
    parse_dialogue_file(game, npc);
    self->draw = &draw_npc_start_dog;
    self->handler = &npc_start_dog_handler;
}
