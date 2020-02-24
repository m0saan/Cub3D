build:
	@gcc -g -I/usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit *.c -g3 -fsanitize=address -fsanitize=undefined -Ofast;
	@rm -rf a.out.dSYM cube3d.h.gch
