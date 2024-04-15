cmake_minimum_required(VERSION 3.20.0)

project(microwar)

add_executable(microwar main.cpp field.cpp board.cpp
    boarddrawer.cpp player.cpp simpleboardgenerator.cpp
    cursor.cpp playerresourcesmanager.cpp
    engine/texturemanager.cpp engine/uimanager.cpp
    engine/controllermapper.cpp engine/soundmanager.cpp)

file(COPY gfx DESTINATION ${CMAKE_BINARY_DIR})
file(COPY sfx DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(microwar PRIVATE raylib)