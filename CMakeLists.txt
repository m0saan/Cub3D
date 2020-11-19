cmake_minimum_required(VERSION 3.17)
project(TEST C)

set(CMAKE_C_STANDARD 99)

add_executable(TEST srcs/main.c
        srcs/ray_casting.c
        srcs/cube3d_utils.c
        srcs/sprite.c
        srcs/events.c
        srcs/map_file_parser.c
        srcs/parse_textures.c
        srcs/parse_map.c
        srcs/parse_floor_ceilling_resolution.c
        srcs/map_file_parser_utils.c
        srcs/render.c
        srcs/utils.c
        srcs/screenshot.c
        srcs/walls.c
        srcs/intersection.c
        srcs/sprite_utils.c
        srcs/sprite_utils2.c
        srcs/wall_utils.c
        srcs/init_data.c
        srcs/utils2.c
        srcs/map_error_handling.c
        srcs/misc.c
        srcs/destruct.c)

target_link_libraries(TEST ${CMAKE_SOURCE_DIR}/libmlx.a ${CMAKE_SOURCE_DIR}/libft.a)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Ofast -fsanitize=address -lm -framework OpenGL -framework AppKit")
