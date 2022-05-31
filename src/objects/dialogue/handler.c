/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler_start.c
*/

#include "rpg.h"
#include "object.h"
#include "dialogue.h"
#include "my.h"

void dialogue_box_set_text(dialogue_box_t *dialogue, char *text)
{
    dialogue->index = 0;
    if (dialogue->content_stripped != NULL)
        free(dialogue->content_stripped);
    dialogue->content = text;
    dialogue->content_stripped = my_strdup(text);
    dialogue->content_stripped[0] = '\0';
    dialogue->max_index = my_strlen(dialogue->content);
    dialogue->finished = false;
    sfText_setString(dialogue->text, dialogue->content_stripped);
}

void dialogue_box_handler(game_t *game, dialogue_box_t *dialogue)
{
    if (dialogue->index >= dialogue->max_index) {
        dialogue->finished = true;
        return;
    }
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    if (diff >= dialogue->delay) {
        dialogue->content_stripped[dialogue->index] =
            dialogue->content[dialogue->index];
        ++dialogue->index;
        dialogue->content_stripped[dialogue->index] = '\0';
        sfText_setString(dialogue->text, dialogue->content_stripped);
        last_clock_us = sfClock_getElapsedTime(
            game->clock->clock).microseconds;
    }
}

void dialogue_handler(game_t *game, struct object_s *self)
{
    dialogue_box_handler(game, self->data);
}
