/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** dialogue
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    enum {
        DLG_BOX_CORNER,
        DLG_BOX_BORDER,
        DLG_BOX_BACKGROUND,
        DLG_BOX_INDICATOR,  // arrow above NPC's head
        DLG_BOX_PART_NB
    };

    typedef struct {
        sfSprite *box_parts[DLG_BOX_PART_NB];
        sfText *text;
        char *content;
        char *content_stripped;
        sfVector2f pos;
        int index; // index of \0 for text animation
        int max_index;
        bool finished;
        float delay;
    } dialogue_box_t;

    #define DLG_BOX_PATH "assets/spritesheets/dialogue.png"

#endif /* !DIALOGUE_H_ */
