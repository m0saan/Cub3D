# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moboustt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 01:32:34 by moboustt          #+#    #+#              #
#    Updated: 2020/11/24 10:05:22 by moboustt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- This is a MakeFile -*- #

NAME = cub3D

SRC_PATH = primary
SRC_NAMES = cube3d_utils.c map_file_parser_utils.c sprite.c destruct.c sprite_utils.c events.c \
			parse_floor_ceilling_resolution.c sprite_utils2.c init_data.c parse_map.c utils.c \
			intersection.c parse_textures.c utils2.c main.c ray_casting.c wall_utils.c \
			map_error_handling.c render.c walls.c map_file_parser.c screenshot.c

SRC_BONUS_NAMES = cube3d_utils.c map_file_parser_utils.c parse_floor_ceilling_resolution.c init_data.c\
                  intersection.c parse_textures.c utils2.c parse_map.c utils.c ray_casting.c \
                  			map_error_handling.c map_file_parser.c screenshot.c wall_utils.c sprite_utils.c
BONUS_PATH = bonus
BONUS_NAMES = render_bonus.c walls_bonus.c destruct_bonus.c events_bonus.c main_bonus.c misc_bonus.c \
			sprite_bonus.c sprite_utils2_bonus.c

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
DEBUG = -g3
OPT = -Ofast -O3
LD_LIBS = -lm -framework OpenGL -framework AppKit libs/libmlx.a

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))
BONUS_SRCS = $(addprefix $(SRC_PATH)/, $(SRC_BONUS_NAMES))
BONUS__ = $(addprefix $(BONUS_PATH)/, $(BONUS_NAMES))

all: $(NAME)

$(NAME): $(SRC)
	@ make -C $(LIBFT_PATH)
	@ $(CC) $(CFLAGS) $(SRC) $(OPT) -o $(NAME) $(LD_LIBS) $(LIBFT)

bonus: fclean $(BONUS_SRCS) $(BONUS__)
	@ make -C $(LIBFT_PATH)
	@  $(CC) $(CFLAGS) $(BONUS_SRCS) $(BONUS__) $(OPT) -o $(NAME) $(LD_LIBS) $(LIBFT)

build:
	@./Cub3D "maps/map.cub"

save:
	@./Cub3D "maps/map.cub" "--save"

norm:
	@ norminette primary
	@ norminette bonus
	@ norminette include

clean:

fclean: clean
	@ rm -rf $(NAME)
	@ make fclean -C $(LIBFT_PATH)

re: fclean all
