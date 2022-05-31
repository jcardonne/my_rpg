/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** npc_handler
*/

#include "rpg.h"
#include "npc.h"
#include "dialogue.h"

void dialogue_box_handler(game_t *game, dialogue_box_t *dialogue);
float calc_distance(sfVector2f point1, sfVector2f point2);
void dialogue_box_set_text(dialogue_box_t *dialogue, char *text);
void change_dialogue_index_animation(game_t *game, npc_t *npc);
float calc_distance_sprite(sfSprite *sprite1, sfSprite *sprite2);

static void animate_dog(game_t *game, npc_t *dog)
{
    static long last_animation = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_animation) / 1000000.0;
    if (diff >= 0.5) {
        dog->entity.rect.left += dog->entity.spritesheet_rect_x;
        sfSprite_setTextureRect(dog->entity.sprite, dog->entity.rect);
        if (dog->entity.rect.left == (dog->entity.spritesheet_width -
                                        dog->entity.spritesheet_rect_x))
            dog->entity.rect.left = 0;
        last_animation = current_us;
    }
}

static void breathing_dog(game_t *game, npc_t *dog)
{
    static long last_breath_in = 0;
    static long last_breath_out = 0;
    static int breath_state = 1;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    sfVector2f scale = sfSprite_getScale(dog->entity.sprite);
    if ((current_us - last_breath_in) / 1000000.0 >= 0.3) {
        scale.x += 0.03 * breath_state;
        scale.y += 0.01 * breath_state;
        sfSprite_setScale(dog->entity.sprite, scale);
        last_breath_in = current_us;
    }
    if ((current_us - last_breath_out) / 1000000.0 >= 1) {
        breath_state = (breath_state == 1) ? -1 : 1;
        last_breath_out = current_us;
    }
}

void npc_start_dog_handler(game_t *game, object_t *self)
{
    player_t *player = game->play->player->data;
    npc_t *npc = self->data;
    breathing_dog(game, npc);
    animate_dog(game, npc);
    if (npc->dialogue_nb == 0)
        return;
    if (calc_distance_sprite(player->entity.sprite, npc->entity.sprite) > 70) {
        npc->dialogue_index = 0;
        npc->is_talking = false;
        return;
    }
    if (!npc->is_talking) {
        npc->is_talking = true;
        dialogue_box_set_text(npc->dialogue,
            npc->dialogue_list[npc->dialogue_line][npc->dialogue_index]);
    }
    change_dialogue_index_animation(game, npc);
    dialogue_box_handler(game, npc->dialogue);
}
