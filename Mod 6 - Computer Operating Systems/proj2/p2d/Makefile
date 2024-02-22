all:	interface3 noise_server

interface2:	interface3.c
	gcc -Wall -ggdb -o interface3 interface3.c

noise_server:	noise_server.c
	gcc -Wall -ggdb -o noise_server noise_server.c

clean:
	rm interface3 noise_server
