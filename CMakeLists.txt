cmake_minimum_required(VERSION 3.0)

project(simple-libwebsockets-example C)

add_executable(client client.c)
add_executable(server server.c)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.html
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(UNIX)
  target_link_libraries(client websockets)
  target_link_libraries(server websockets)

  add_definitions(-DLINUX)
  message("Building for Linux")
endif()

if(WIN32)
  include_directories("./libwebsockets/build") #libwebsockets.h
  include_directories("./libwebsockets/lib") #lws_config.h
  include_directories("C:/OpenSSL-Win32/include")

  file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libwebsockets/build/bin/websockets.dll
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

  target_link_libraries(server "${CMAKE_CURRENT_SOURCE_DIR}/libwebsockets/build/lib/*.lib")
  target_link_libraries(client "${CMAKE_CURRENT_SOURCE_DIR}/libwebsockets/build/lib/*.lib")

  add_definitions(-DWINDOWS)
  message("Building for Windows")
endif()