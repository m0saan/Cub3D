# -*- This is a MakeFile -*- #

NAME = Cub3D
SRC_PATH = srcs
SRC_NAMES = *.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAMES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
DEBUG = -g3
OPT = -Ofast
LD_LIBS = -lm -framework OpenGL -framework AppKit libmlx.a -fsanitize=address
LIB_FT = libft.a

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


all: $(NAME)

$(NAME):
	@$(CC) $(LIB_FT) $(DEBUG) $(LD_LIBS) $(SRC) -o $(NAME) $(OPT);

clean:
	@rm -rf *.o
	@echo "Makefile : Cleaning .o files..."

build:
	@./Cub3D "map.cub"

fclean: clean
	@rm -rf $(NAME)
	@echo "Makefile : Clean .a files..."

re: fclean all
