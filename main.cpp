#include "raylib.h"

#include "player.hpp"
#include "board.hpp"
#include "boarddrawer.hpp"
#include "simpleboardgenerator.hpp"
#include "texturemanager.hpp"

int main(int argc, char **argv)
{
    const int screenWidth = 320;
    const int screenHeight = 320;

    const float battlegroundWidth = 11;
    const float battlegroundHeight = 11;

    const int xOffset = 23;
    const int yOffset = 23;

    auto textureManager = std::make_unique<TextureManager>();
    textureManager->addTexture("village", "gfx/village-tile.png");
    textureManager->addTexture("castle", "gfx/castle-tile.png");
    textureManager->addTexture("empty", "gfx/empty-tile.png");

    Player player;
    Board board;
    BoardDrawer drawer(board, std::move(textureManager));
    SimpleBoardGenerator boardGenerator;
    boardGenerator.generateBoard(board);

    InitWindow(screenWidth, screenHeight, "MicroWar");

    SetTargetFPS(30);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        drawer.draw("village", xOffset, yOffset);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}