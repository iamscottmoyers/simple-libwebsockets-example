all: server client

server: server.c
	gcc -g -Wall `pkg-config libwebsockets --libs --cflags` $< -o $@
client: client.c
	gcc -g -Wall `pkg-config libwebsockets --libs --cflags` $< -o $@

clean:
	rm -f server
	rm -rf server.dSYM
	rm -f client
	rm -rf client.dSYM
