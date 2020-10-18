# -*- This is a MakeFile -*- #

NAME = Cub3D
SRC_PATH = srcs
SRC_NAMES = *.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAMES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
DEBUG = -g3
OPTIMAZATION = -Ofast
LDLIBS = -lm -framework OpenGL -framework AppKit libmlx.a -fsanitize=address

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


all: $(NAME)

$(NAME):
	@$(CC) $(DEBUG) $(LDLIBS) $(SRC) -o $(NAME);

clean:
	@rm -rf *.o
	@echo "Makefile : Cleaning .o files..."

build:
	@./Cub3D map.cub

fclean: clean
	@rm -rf $(NAME)
	@echo "Makefile : Clean .a files..."

re: fclean all
