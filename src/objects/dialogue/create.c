/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create.c
*/

#include "ui.h"
#include "my.h"
#include "game.h"
#include "dialogue.h"

const static sfIntRect BOX_RECT[DLG_BOX_PART_NB] = {
    {0, 0, 4, 4}, // corner
    {3, 0, 1, 4}, // border
    {1, 3, 1, 1}, // background
    {4, 0, 8, 4} // indicator (arrow)
};

dialogue_box_t *create_dialogue_data(game_t *game)
{
    dialogue_box_t *dialogue = malloc(sizeof(dialogue_box_t));
    static sfTexture *dialogue_texture = NULL;
    if (dialogue_texture == NULL)
        dialogue_texture = sfTexture_createFromFile(DLG_BOX_PATH, NULL);
    for (int i = 0; i < DLG_BOX_PART_NB; ++i) {
        dialogue->box_parts[i] = sfSprite_create();
        sfSprite_setTexture(dialogue->box_parts[i], dialogue_texture, sfFalse);
        sfSprite_setTextureRect(dialogue->box_parts[i], BOX_RECT[i]);
        sfSprite_setOrigin(dialogue->box_parts[i], (sfVector2f){
            BOX_RECT[i].width / 2, BOX_RECT[i].height / 2});
    }
    dialogue->text = sfText_create();
    sfText_setFont(dialogue->text, game->data.retro_font);
    sfText_setScale(dialogue->text, (sfVector2f){0.2, 0.2});
    sfText_setFillColor(dialogue->text, sfBlack);
    dialogue->index = 0;
    dialogue->content = NULL;
    dialogue->content_stripped = NULL;
    dialogue->finished = false;
    return dialogue;
}
