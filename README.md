# simple-libwebsockets-example

A simple libwebsockets example.

Like http://ahoj.io/libwebsockets-simple-websocket-server I found the libwebsockets
examples here https://github.com/warmcat/libwebsockets/blob/master/test-server too
complicated.

I wanted to be able to serve a simple html file and also have a C client send some data
to the server so created this.

## Build
```bash
make
```

## Run
In one terminal run:
```bash
./server
```

In another terminal run:
```bash
./client
```

Then navigate to localhost:8000 in your web browser. You should see a random number being
updated every second.
