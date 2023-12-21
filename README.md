# ⛔️ DEPRECATED - simple-libwebsockets-example

[![No Maintenance Intended](http://unmaintained.tech/badge.svg)](http://unmaintained.tech/)

I looked at `libwebsockets` for a week whilst in-between jobs in 2015, since then I haven't used the API. I'm pretty sure I wasn't using it correctly to start with as they've since updated the API in a way that's incompatible with how I was using it, the `lws_service` timeout is now ignored and my code relied on the timeout occurring to run a polling loop.

The simple-libwebsockets-example name must be good as apparently it's a top hit when searching. If anyone finds better simple libwebsockets examples let me know and I can link to them here. Alternatively if anyone else attempts to fix this repo in a way I can easily validate I'll happily merge the changes.

The original documentation for this project follows.

-----

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
