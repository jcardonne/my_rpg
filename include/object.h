/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** objects
*/

#ifndef OBJECTS_H_
    #define OBJECTS_H_

    #include "region.h"
    #include "entity.h"
    #include "particles.h"

    #define NB_ARGS_SMOKE 3
    #define CAST_SMOKE(arg) ((smoke_t *)(arg))
    #define NB_ARGS_WAVES 3
    #define SPRITE_ENEMY ((enemy_t *)(self->data))->entity.sprite
    #define NB_ARGS_ENEMY 5
    #define CAST_ENEMY(arg) ((enemy_t *)(arg))
    #define M_PI 3.14159265358979323846
    #define DEG_TO_RAD(x) ((x) * M_PI / 180)
    #define NB_ARGS_BORDER_WAVES 5
    #define NB_ARGS_ITEM 5
    #define INVENTORY_SIZE 10
    #define ITEM_REGISTER 1
    #define NB_ARGS_GRASS 2

    enum id_object_type {
        TELEPORTER_OBJ,
        DIALOGUE_OBJ,
        SMOKE_OBJ,
        WAVES_OBJ,
        ENEMY_OBJ,
        WAVES_BORDER_OBJ,
        CLOCK_OBJ,
        BACKGROUND_UI_OBJ,
        HEARTS_UI_OBJ,
        NPC_OBJ,
        MUSIC_OBJ,
        ITEMS_OBJ,
        GRASS_OBJ,
        OBJECT_NB,
    };

    enum orientation {
        RIGHT,
        LEFT,
        DOWN,
        UP,
        DEAD
    };

    enum id_enemies {
        BLOB,
        SLIME,
        SKELETON,
        NB_ENEMIES
    };

    enum jump_state {
        STATIC,
        MOVING,
        JUMPING
    };

    #define SLIME_PATH "assets/spritesheets/slime.png"
    #define GHOST_PATH "assets/spritesheets/ghost.png"
    #define SKELETON_PATH "assets/spritesheets/skeleton.png"
    #define BLOB_PATH "assets/spritesheets/blob.png"
    #define DOG_PATH "assets/spritesheets/dog.png"

    typedef struct {
        sfFloatRect area;
        region_t *dest_region;
    } teleporter_t;

    typedef struct smoke {
        int offset_x;
        int offset_pos_x;
        int offset_pos_y;
        sfSprite *sprite;
        sfVector2f pos;
    } smoke_t;

    typedef struct waves {
        long last_clock;
        sfSprite *sprite;
        int offset_x;
        sfVector2f pos;
    } waves_t;

    typedef struct waves_border {
        sfSprite *sprite;
        int offset_x;
        int offset_y;
        sfVector2f pos;
        int direction;
        long last_clock;
    } waves_border_t;

    typedef struct grass {
        sfSprite *sprite;
        int offset_x;
        sfVector2f pos;
        int destroyed;
        long last_animation;
        int is_hit;
    } grass_t;

    typedef struct stats_s {
        int damage;
        int life_points;
        int range_aggro;
        int speed;
    } stats_t;

    typedef struct animation_data {
        long last_breathing_animation;
        long last_breath_out_animation;
        long last_move_animation;
        long last_movement;
        long last_idle_state;
        int animation_state;
        int breath_state;
        int distance_jumped;
        int jump_height;
        int animate_death;
        long last_death_animation;
    } animation_data_t;

    typedef struct enemy {
        int id;
        int trigerred;
        int bouncing;
        sfVector2f self_pos;
        sfVector3f coords_3d;
        sfVector2i translation;
        sfVector2f *pos;
        int where_to_go;
        entity_t entity;
        stats_t stats;
        sfVector2f direction;
        sfVector2f direction_3d;
        animation_data_t animation_data;
        int offset_x;
        int offset_y;
        int is_hit;
        long invincibility;
        int dead;
        linked_list_t *emitters;
    } enemy_t;

    typedef struct {
        sfText *text;
        long last_clock;
    } clock_object_t;

    typedef struct object_s {
        enum id_object_type id;
        void *data;
        void (*handler)();
        void (*draw)();
    } object_t;

    typedef struct {
        object_t *items[INVENTORY_SIZE];
        int nb_items;
        sfText *health_text;
        sfText *attack_text;
    } inventory_t;

    typedef struct explosion {
        sfSprite *sprite;
        int activated;
        long last_animation;
        int offset_x;
        int done;
        int loaded;
    } explosion_t;

    #define START_REGION_X 2
    #define START_REGION_Y 3

    typedef struct {
        inventory_t inventory;
        entity_t entity;
        int speed;
        int attack;
        int health;
        int is_hit;
        linked_list_t *emitters;
        int orientation;
        long hit_delay;
    } player_t;

    #define CAST_PLAYER(arg) ((player_t *)(arg))

#endif /* !OBJECTS_H_ */
