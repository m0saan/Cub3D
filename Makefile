# -*- This is a MakeFile -*- #

NAME = Cub3D
SRC_PATH = srcs
SRC_NAMES = cube3d_utils.c map_file_parser_utils.c sprite.c destruct.c misc.c sprite_utils.c events.c \
parse_floor_ceilling_resolution.c sprite_utils2.c init_data.c parse_map.c utils.c intersection.c \
parse_textures.c utils2.c main.c ray_casting.c wall_utils.c map_error_handling.c render.c \
walls.c map_file_parser.c screenshot.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAMES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
DEBUG = -g3
OPT = -Ofast
LD_LIBS = -lm -framework OpenGL -framework AppKit libmlx.a libft.a

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


all: $(NAME)
	 @echo "Build successful!"

$(NAME): $(OBJ)
	@echo "linking..."
	@ $(CC) $(OBJ) -o $(NAME) $(LD_LIBS)

$(OBJ):
	@echo "Compiling..."
	@ $(CC) -c $(CFLAGS) $(DEBUG) $(SRC) $(OPT)
	@ mv *.o $(OBJ_PATH)

clean:
	@ rm -rf $(OBJ_PATH)/*.o
	@echo "Makefile : Cleaning .o files..."

build:
	@./Cub3D "maps/map.cub"

save:
	@./Cub3D "maps/map.cub" "--save"

fclean: clean
	@ rm -rf $(NAME)

re: fclean all
