build:
	@gcc -I/usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit *.c -g3 -fsanitize=address -pedantic;
	@./a.out;
	@rm -rf a.out.dSYM cube3d.h.gch

clean:
	rm raycast;
