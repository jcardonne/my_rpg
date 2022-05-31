/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "my.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);
void events_handler_settings_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

static void draw_music_volume(game_t *game)
{
    static int music_volume = -1;
    if (game->settings.volume_music != music_volume ||
        game->settings.music_text == NULL) {
        music_volume = game->settings.volume_music;
        char *str = my_int_to_strnum(game->settings.volume_music);
        game->settings.music_text = sfText_create();
        sfText_setPosition(game->settings.music_text, (sfVector2f){885, 365});
        sfText_setScale(game->settings.music_text, (sfVector2f){1.5, 1.5});
        sfText_setString(game->settings.music_text, str);
        sfText_setFont(game->settings.music_text, game->data.retro_font);
    }
    sfRenderWindow_drawText(game->window, game->settings.music_text, NULL);
}

static void draw_general_volume(game_t *game)
{
    static int general_volume = -1;
    if (game->settings.general_volume != general_volume ||
        game->settings.general_text == NULL) {
        general_volume = game->settings.general_volume;
        char *str = my_int_to_strnum(game->settings.general_volume);
        game->settings.general_text = sfText_create();
        sfText_setPosition(game->settings.general_text,
                            (sfVector2f){885, 460});
        sfText_setScale(game->settings.general_text, (sfVector2f){1.5, 1.5});
        sfText_setString(game->settings.general_text, str);
        sfText_setFont(game->settings.general_text, game->data.retro_font);
    }
    sfRenderWindow_drawText(game->window, game->settings.general_text, NULL);
}

static void draw_settings(game_t *game)
{
    static sfSprite *sprite = NULL;
    if (sprite == NULL) {
        sprite = sfSprite_create();
        sfTexture *texture =
            sfTexture_createFromFile("assets/images/settings.png", NULL);
        sfSprite_setTexture(sprite, texture, sfFalse);
    }
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    draw_music_volume(game);
    draw_general_volume(game);
    return;
}

void settings_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, (sfColor){28, 28, 28, 255});
    events_handler_settings_scene(game);
    handle_object(game);
    if (game->current_scene != SETTINGS_SCENE)
        return;
    game->scene[SETTINGS_SCENE]->emitter->
                                ptr_part(game->scene[SETTINGS_SCENE]->emitter,
                                SNOW, (sfVector2f){0.0, 0.0}, game->window);
    draw_settings(game);
    draw_scene(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}