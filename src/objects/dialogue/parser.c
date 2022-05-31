/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"
#include "dialogue.h"

dialogue_box_t *create_dialogue_data(game_t *game);
void dialogue_handler(game_t *game, struct object_s *self);
void draw_dialogue(game_t *game, struct object_s *self);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
float ratof(char *arr);

char *replace_char_by_char(char *str, char c1, char c2)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == c1)
            str[i] = c2;
    return str;
}

void parse_dialogue_box(game_t *game, region_t *region, char **argv)
{
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 4)
        return;
    dialogue_box_t *dialogue = create_dialogue_data(game);
    dialogue->pos.x = my_getnbr(argv[0]);
    dialogue->pos.y = my_getnbr(argv[1]);
    dialogue->content = replace_char_by_char(my_strdup(argv[2]), '|', '\n');
    dialogue->content_stripped = my_strdup(dialogue->content);
    dialogue->max_index = my_strlen(dialogue->content);
    dialogue->delay = ratof(argv[3]);
    object_t *object = create_object(DIALOGUE_OBJ, dialogue,
        &dialogue_handler, &draw_dialogue);
    my_put_in_list(&region->objects, object);
}
