# -*- This is a MakeFile -*- #

NAME = Cub3D
SRC_PATH_PATH = srcs
SRC_NAMES = *.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAMES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
DEBUG = -g
OPTIMAZATION = -Ofast
LDLIBS = -lm -framework OpenGL -framework AppKit libmlx.a

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


all: $(NAME)

$(NAME):
	@$(CC) $(DEBUG) $(LDLIBS) $(SRC_NAMES) $(OPTIMAZATION) -o $(NAME);
	@rm -rf a.out.dSYM cube3d.h.gch

clean:
	@rm -rf *.o
	@echo "Makefile : Cleaning .o files..."

fclean: clean
	@rm -rf $(NAME) *.a
	@echo "Makefile : Clean .a files..."

re: fclean all
