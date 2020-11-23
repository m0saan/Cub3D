cmake_minimum_required(VERSION 3.17)
project(TEST C)

set(CMAKE_C_STANDARD 99)

add_executable(TEST primary/main.c
        primary/ray_casting.c
        primary/cube3d_utils.c
        primary/sprite.c
        primary/events.c
        primary/map_file_parser.c
        primary/parse_textures.c
        primary/parse_map.c
        primary/parse_floor_ceilling_resolution.c
        primary/map_file_parser_utils.c
        primary/render.c
        primary/utils.c
        primary/screenshot.c
        primary/walls.c
        primary/intersection.c
        primary/sprite_utils.c
        primary/sprite_utils2.c
        primary/wall_utils.c
        primary/init_data.c
        primary/utils2.c
        primary/map_error_handling.c
        primary/destruct.c)

target_link_libraries(TEST ${CMAKE_SOURCE_DIR}/libs/libmlx.a ${CMAKE_SOURCE_DIR}/libs/libft.a)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Ofast -fsanitize=address -lm -framework OpenGL -framework AppKit")
