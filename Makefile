build:
	gcc -I/usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit *.c -g3 -fsanitize=address ;
	./a.out;

clean:
	rm raycast;
