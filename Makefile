build:
	gcc -I/usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit main.c cube3d.h -g3 -fsanitize=address -pedantic;
	./a.out;

clean:
	rm raycast;
