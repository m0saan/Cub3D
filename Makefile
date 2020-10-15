# -*- This is a MakeFile -*- #

NAME = Cub3D
SRC_PATH = srcs
SRC_NAMES = *.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAMES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
DEBUG = -g
OPTIMAZATION = -Ofast
LDLIBS = -lm -framework OpenGL -framework AppKit libmlx.a
ADDRESS_SANITIZER = -fsanitize=address

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


all: $(NAME)

$(NAME):
	@$(CC) $(DEBUG) $(CFLAGS) $(LDLIBS) $(OPTIMAZATION) $(SRC) -o $(NAME) $(ADDRESS_SANITIZER);

build:
	@./Cub3D map2.cub
	
clean:
	@rm -rf *.o
	@echo "Makefile : Cleaning .o files..."

fclean: clean
	@rm -rf $(NAME)
	@echo "Makefile : Clean .a files..."

re: fclean all
