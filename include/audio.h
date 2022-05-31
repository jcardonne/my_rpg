/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** audio
*/

#ifndef AUDIO_H_
    #define AUDIO_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    enum {
        MAIN_MUSIC,
        DUNGEON_MUSIC,
        MUSIC_NB,
    };

    static const char *MUSIC_PATH[MUSIC_NB] = {
        "assets/audio/main_music.wav",
        "assets/audio/dungeon_music.wav",
    };

    typedef struct {
        sfMusic *music;
        sfSound *jump;
        sfSound *player_death;
        sfSound *skeleton_death;
        sfSound *slime_death;
    } audio_t;

#endif /* !AUDIO_H_ */
