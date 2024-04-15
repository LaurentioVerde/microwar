#include "raylib.h"

#include "engine/uimanager.hpp"
#include "engine/texturemanager.hpp"
#include "engine/controllermapper.hpp"
#include "engine/soundmanager.hpp"

#include "player.hpp"
#include "board.hpp"
#include "boarddrawer.hpp"
#include "simpleboardgenerator.hpp"
#include "cursor.hpp"
#include "playerresourcesmanager.hpp"

int main(int argc, char **argv)
{
    const int screenWidth = 320;
    const int screenHeight = 320;

    const float battlegroundWidth = 11;
    const float battlegroundHeight = 11;

    BoardInfo boardInfo = {23, 23, 24};

    InitWindow(screenWidth, screenHeight, "MicroWar");
    InitAudioDevice();

    auto textureManager = std::make_shared<TextureManager>();
    textureManager->addTexture("village", "gfx/village-tile.png");
    textureManager->addTexture("tower", "gfx/tower-tile.png");
    textureManager->addTexture("empty", "gfx/empty-tile.png");
    textureManager->addTexture("city", "gfx/city-tile.png");
    textureManager->addTexture("cursor", "gfx/cursor.png");

    Player player(ORANGE, "Player");
    Player artificalPlayer(RED, "AI");
    std::vector<Player*> players = {&player, &artificalPlayer};

    ControllerMapper mapper;

    Board board;
    BoardDrawer drawer(board, boardInfo, textureManager);
    drawer.linkResource(FieldType::Village, "village");
    drawer.linkResource(FieldType::Unoccupied, "empty");
    drawer.linkResource(FieldType::City, "city");
    drawer.linkResource(FieldType::Tower, "tower");

    SimpleBoardGenerator boardGenerator;
    boardGenerator.generateBoard(board);
    boardGenerator.assignPlayers(board, players);

    auto cursor = std::make_unique<Cursor>("cursor", Color{100, 255, 0, 255}, board, boardInfo);
    cursor->deduceCursorInitialPosition();

    SoundManager soundManager;
    soundManager.addSound({CursorConsts::rightActionName,
        CursorConsts::leftActionName,
        CursorConsts::upActionName,
        CursorConsts::downActionName}, "sfx/cursor.wav");

    UIManager manager(textureManager);
    manager.addElement(std::move(cursor));

    manager.invokeAction(std::string(CursorConsts::upActionName));
    manager.invokeAction(std::string(CursorConsts::upActionName));

    mapper.addInvokable(&manager);
    mapper.addInvokable(&soundManager);
    mapper.mapControl(KEY_UP, CursorConsts::upActionName);
    mapper.mapControl(KEY_DOWN, CursorConsts::downActionName);
    mapper.mapControl(KEY_LEFT, CursorConsts::leftActionName);
    mapper.mapControl(KEY_RIGHT, CursorConsts::rightActionName);

    PlayerResourcesManager playerManager(board, player);
    playerManager.calculatePlayerActionPoints();

    SetTargetFPS(30);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        mapper.process();
        drawer.draw();
        manager.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}