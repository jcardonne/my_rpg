/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** restart_clock
*/

#include <stddef.h>
#include <stddef.h>
#include "game.h"
#include "my.h"

int my_put_in_list(struct linked_list **list, void *data);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

void restart_clock(game_t *game, clock_object_t *clock)
{
    clock->last_clock =
        sfClock_getElapsedTime(game->clock->clock).microseconds;
    game->clock->seconds = 60;
    sfText_setString(clock->text, "60");
}

void draw_clock_object_text(game_t *game, object_t *self)
{
    clock_object_t *clock = self->data;
    sfFloatRect rect = sfText_getGlobalBounds(clock->text);
    sfText_setPosition(clock->text, (sfVector2f){112 - rect.width / 2,
        92 - rect.height / 2});
    sfRenderWindow_drawText(game->window, clock->text, NULL);
}

void handler_clock_object_text(game_t *game, object_t *self)
{
    clock_object_t *clock = self->data;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - clock->last_clock) / 1000000.0;

    if (diff >= 1 && !game->debug_mode) {
        game->clock->seconds -= 1;
        if (game->clock->seconds < 0) {
            restart_clock(game, clock);
            CAST_PLAYER(game->play->player->data)->health = 0;
            return;
        }
        sfText_setString(clock->text,
            my_int_to_strnum((int)game->clock->seconds));
        clock->last_clock =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

object_t *init_clock_object_text(game_t *game)
{
    clock_object_t *clock = malloc(sizeof(clock_object_t));
    clock->text = sfText_create();
    object_t *object = NULL;
    clock->last_clock = 0;

    sfText_setFont(clock->text, game->data.retro_font);
    sfText_setScale(clock->text, (sfVector2f){1, 1});
    sfText_setCharacterSize(clock->text, 50);
    sfText_setString(clock->text, "60");
    game->clock->seconds = 60;
    object = create_object(CLOCK_OBJ, clock,
                        &handler_clock_object_text, &draw_clock_object_text);
    object->id = CLOCK_OBJ;
    return object;
}
