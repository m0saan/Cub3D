build:
	@gcc -I/usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit *.c -g3 -fsanitize=address -Ofast;
	@rm -rf a.out.dSYM cube3d.h.gch
