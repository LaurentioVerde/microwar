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

    InitWindow(screenWidth, screenHeight, "MicroWar");

    auto textureManager = std::make_unique<TextureManager>();
    textureManager->addTexture("village", "gfx/village-tile.png");
    textureManager->addTexture("tower", "gfx/tower-tile.png");
    textureManager->addTexture("empty", "gfx/empty-tile.png");
    textureManager->addTexture("city", "gfx/city-tile.png");

    Player player(ORANGE);
    Player artificalPlayer(RED);
    std::vector<Player*> players = {&player, &artificalPlayer};

    Board board;
    BoardDrawer drawer(board, std::move(textureManager));
    drawer.linkResource(FieldType::Village, "village");
    drawer.linkResource(FieldType::Unoccupied, "empty");
    drawer.linkResource(FieldType::City, "city");
    drawer.linkResource(FieldType::Tower, "tower");

    SimpleBoardGenerator boardGenerator;
    boardGenerator.generateBoard(board);
    boardGenerator.assignPlayers(board, players);

    SetTargetFPS(30);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        drawer.draw(xOffset, yOffset);

        EndDrawing();
    }

    textureManager.release();

    CloseWindow();

    return 0;
}