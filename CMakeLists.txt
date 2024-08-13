cmake_minimum_required(VERSION 3.20.0)
set(CXX_STANDARD 20)

project(microwar)

include_directories(.)

add_executable(microwar main.cpp
    core/gameloop.cpp
    board/board.cpp
    board/boarddrawer.cpp
    board/field.cpp
    board/simpleboardgenerator.cpp
    player/player.cpp
    player/playerresourcesmanager.cpp
    player/playerscontroller.cpp
    units/basicunit.cpp
    units/basicunitfactory.cpp
    units/simpleunitspopulator.cpp
    units/unitsmanager.cpp
    ui/cursor.cpp
    ui/resourcesuielement.cpp
    engine/drawingmanager.cpp
    engine/controllermapper.cpp
    engine/soundmanager.cpp
    engine/texturemanager.cpp
    engine/uimanager.cpp)

file(COPY gfx DESTINATION ${CMAKE_BINARY_DIR})
file(COPY sfx DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(microwar PRIVATE raylib)