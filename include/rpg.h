/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <time.h>

    #include "entity.h"
    #include "time.h"
    #include "ui.h"
    #include "particles.h"
    #include "option.h"
    #include "region.h"
    #include "game.h"

    my_time_t *init_clock(void);

    /* Drawing */
    void draw_list_entity(game_t *game, linked_list_t **list);
    void draw_entity(game_t *game, entity_t *entity);

    /* Init */
    entity_t *init_entity(option_t option);

    /* Interactions */
    void check_mouse_movement(game_t *game);

    /* Manipulation */
    sfVector2f move_coords(sfVector2f pos, float x, float y);
    int set_text_from_textures(entity_t entity, int n);

    /* Animation */
    void play_animate_sprites(game_t *game, int status);
    void rect_animation_horizontal(game_t *game, entity_t *entity);
    void rect_list_animation(game_t *game, linked_list_t **list);

    /* Regions */
    void draw_region(game_t *game, region_t *region);
    void init_all_regions(game_t *game);

    // Events
    void move_player(game_t *game, player_t *player,
        float shift_x, float shift_y);

    // Inventory
    void set_inventory_data(game_t *game, void *data, int n);
    item_t *get_inventory_data(game_t *game, int n);
    item_t *create_items_object(option_t option, int unlocked, int id);

#endif /* !RPG_H_ */
