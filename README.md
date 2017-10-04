# simple-libwebsockets-example

A simple libwebsockets example.

Like http://ahoj.io/libwebsockets-simple-websocket-server I found the libwebsockets
examples here https://github.com/warmcat/libwebsockets/blob/master/test-server too
complicated.

I wanted to be able to serve a simple html file and also have a C client send some data
to the server so created this.

<details>
  <summary>
      1) Building in Linux (click to expand)
  </summary>
    
1. Install libwebsockets in the conventional way
3. In root folder, create an build folder
```
$ mkdir build; cd build
```
4. Prepare the development and build
```
$ cmake ..
$ make
```
</details>

<details>
  <summary>
      2) Building in Windows (click to expand)
  </summary>

1. Install OpenSSL, cmake and Visual Studio

2. Clone this repository and init submodule repository
```
git submodule init
git submoudle update
```

3. In root folder, create an build folder
```
md build; cd build
``` 

4. Execute these following commands in "Developer Command Prompt for Visual Studio" inside build folder
```
cmake .. -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=RELEASE
nmake

```
</details>


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
