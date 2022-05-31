##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

FILE_NAME	:=	main 													\
			drawing/cursor 												\
			drawing/entity 												\
			init/cursor 												\
			init/window 												\
			init/entity 												\
			init/time 													\
			init/emitter 												\
			init/data 													\
			interactions/entity_region_collision 						\
			interactions/check_collision 								\
			utils/free 													\
			utils/help 													\
			utils/arr_copy 												\
			utils/cut_str 												\
			utils/coords 												\
			utils/extend_str 											\
			utils/random 												\
			utils/calc_dist												\
			utils/lists/my_put_in_list 									\
			utils/lists/my_list_size 									\
			utils/atof													\
			utils/normalize												\
			utils/calc_vector 											\
			events/mouse_events 										\
			events/exit 												\
			events/play_events 											\
			particles_engine/snow/gen_snow 								\
			particles_engine/snow/update_snow 							\
			particles_engine/utils_particles/utils_particles 			\
			particles_engine/draw_particles 							\
			particles_engine/particles_engine 							\
			particles_engine/blood/update_blood 						\
			particles_engine/blood/gen_blood 							\
			regions/create_region 										\
			regions/loop_region 										\
			regions/change_region 										\
			regions/parser 												\
			scene/set_scene 											\
			scene/set_in_game_scenes 									\
			scene/set_end_scene 										\
			scene/game/display 											\
			scene/game/events_handler 									\
			scene/game/init 											\
			scene/game/ui/clock/handle_clock							\
			scene/game/ui/background/handle_background					\
			scene/game/ui/hearts/handle_hearts							\
			scene/game/reset_game 										\
			scene/settings/display 										\
			scene/settings/events_handler 								\
			scene/settings/init 										\
			scene/start_menu/display 									\
			scene/start_menu/event_handler 								\
			scene/start_menu/init 										\
			scene/inventory/display 									\
			scene/inventory/events_handler 								\
			scene/inventory/init 										\
			scene/pause/display 										\
			scene/pause/events_handler 									\
			scene/pause/init 											\
			scene/help/display 											\
			scene/help/events_handler 									\
			scene/help/init 											\
			scene/death/display 										\
			scene/death/events_handler 									\
			scene/death/init 											\
			scene/end_blob/display 										\
			scene/end_blob/event_handler 								\
			scene/end_blob/init 										\
			scene/end_blob/helper_explosions 							\
			scene/end_blob/draw_background 								\
			scene/end_blob/go_to_start_house 							\
			scene/draw_scene 											\
			scene/handle_object 										\
			scene/parse_object											\
			scene/return_to_previous_scene 								\
			maps/create_map 											\
			objects/player/create 										\
			objects/player/handler 										\
			objects/player/draw 										\
			objects/player/utils/get_pos_player 						\
			objects/player/utils/player_hit 							\
			objects/player/animation/interaction 						\
			objects/player/animation/move 								\
			objects/player/animation/attack								\
			objects/player/animation/collisions_with_sword 				\
			objects/player/move 										\
			objects/items/create 										\
			objects/items/draw 											\
			objects/items/parser 										\
			objects/items/handler 										\
			objects/items/sword/hit_effects 							\
			objects/items/sword/set_pos_hit 							\
			objects/create_object 										\
			objects/teleporter/draw 									\
			objects/teleporter/create 									\
			objects/teleporter/parser 									\
			objects/teleporter/handler 									\
			objects/buttons/create 										\
			objects/buttons/draw_start 									\
			objects/buttons/handler_start 								\
			objects/buttons/parser										\
			objects/smoke/create 										\
			objects/smoke/draw 											\
			objects/smoke/handler 										\
			objects/smoke/parser 										\
			objects/waves/create 										\
			objects/waves/draw 											\
			objects/waves/handler 										\
			objects/waves/parser 										\
			objects/waves_border/create 								\
			objects/waves_border/draw 									\
			objects/waves_border/handler 								\
			objects/waves_border/parser 								\
			settings/reset_settings 									\
			settings/set_general_volume 								\
			settings/set_music_volume									\
			objects/dialogue/create 									\
			objects/dialogue/draw 										\
			objects/dialogue/handler	 								\
			objects/dialogue/parser										\
			objects/enemy/props_enemy/option_enemy  					\
			objects/enemy/props_enemy/stats_enemy  						\
			objects/enemy/handler    									\
			objects/enemy/create   										\
			objects/enemy/parser 										\
			objects/enemy/draw											\
			objects/npc/parser											\
			objects/npc/dialogue_file_parser							\
			objects/npc/start_ghost/create								\
			objects/npc/start_ghost/draw								\
			objects/npc/start_ghost/handler								\
			objects/npc/start_ghost/quest								\
			objects/npc/start_dog/create								\
			objects/npc/start_dog/draw									\
			objects/npc/start_dog/handler								\
			objects/enemy/animation/handle_jump 						\
			objects/enemy/animation/reset_jump_state 					\
			objects/enemy/blob/move_blob 								\
			objects/enemy/blob/blob_jump 								\
			objects/enemy/skeleton/move_skeleton 						\
			objects/enemy/skeleton/init_bounce 							\
			objects/enemy/slime/move_slime 								\
			objects/enemy/slime/slime_jump 								\
			objects/enemy/utils/change_direction 						\
			objects/enemy/utils/in_range_player 						\
			objects/enemy/utils/isometry/create_translation 			\
			objects/enemy/utils/isometry/get_destination_3d 			\
			objects/enemy/utils/isometry/get_pos_player_projected 		\
			objects/enemy/utils/isometry/project_iso_point 				\
			objects/enemy/utils/hit_enemy								\
			objects/music/handler										\
			objects/music/parser										\
			objects/grass/create 										\
			objects/grass/draw 											\
			objects/grass/handler 										\
			objects/grass/parser 										\
			audio/sound													\
			save/save													\
			inventory/add_item	 										\
			inventory/getter 											\
			inventory/init


BUILD_DIR 	:=		build/

SRC_DIR		:=		src/

EXT			:=		.c

FILE		:= 		$(addsuffix $(EXT), $(FILE_NAME))

SRC         :=      $(addprefix $(SRC_DIR), $(FILE))

INC_DIR 	:= 		include/

LIB			:=		-l csfml-graphics -l csfml-window
LIB			+=		-l csfml-system -l csfml-audio -lm

OBJECTS    	:=    	$(addprefix $(BUILD_DIR), $(SRC:$(SRC_DIR)%.c=%.o))

NAME 		:=     	my_rpg

CFLAGS 		:= 		$(LIB) -ggdb3 -O1 -g

all: $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C lib/my/
	@gcc $(OBJECTS)  -L ./lib/my -lmy $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BUILD_DIR)

re: fclean all
