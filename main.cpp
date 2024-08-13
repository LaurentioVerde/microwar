#include "raylib.h"

#include "engine/uimanager.hpp"
#include "engine/texturemanager.hpp"
#include "engine/controllermapper.hpp"
#include "engine/soundmanager.hpp"
#include "engine/drawingmanager.hpp"

#include "player/player.hpp"
#include "board/board.hpp"
#include "board/boarddrawer.hpp"
#include "board/simpleboardgenerator.hpp"
#include "ui/cursor.hpp"
#include "player/playerresourcesmanager.hpp"
#include "ui/resourcesuielement.hpp"
#include "units/unitsmanager.hpp"
#include "units/simpleunitspopulator.hpp"
#include "player/playerscontroller.hpp"
#include "core/gameloop.hpp"

int main(int argc, char **argv)
{
    const int screenWidth = 400;
    const int screenHeight = 320;

    const float battlegroundWidth = 11;
    const float battlegroundHeight = 11;

    const std::pair<int, int> offsetGUIUp(120, 4);
    const std::pair<int, int> offsetGUIDown(120, 304);

    BoardInfo boardInfo = {120, 23, 24};

    DrawingManager drawingManager;

    InitWindow(screenWidth, screenHeight, "MicroWar");
    InitAudioDevice();

    auto textureManager = std::make_shared<TextureManager>();
    textureManager->addTexture("village", "gfx/village-tile.png");
    textureManager->addTexture("tower", "gfx/tower-tile.png");
    textureManager->addTexture("empty", "gfx/empty-tile.png");
    textureManager->addTexture("city", "gfx/city-tile.png");
    textureManager->addTexture("cursor", "gfx/cursor.png");

    textureManager->addTexture("actionPoint", "gfx/action-point.png");

    textureManager->addTexture("foodIcon", "gfx/food-icon.png");
    textureManager->addTexture("taxIcon", "gfx/tax-icon.png");

    textureManager->addTexture("soldier", "gfx/soldier.png");

    PlayersController playersController;
    playersController.createPlayer(GREEN, "Player");
    playersController.createPlayer(ORANGE, "AI");

    ControllerMapper mapper;

    Board board;
    BoardDrawer boardDrawer(board, boardInfo, textureManager);
    boardDrawer.linkResource(FieldType::Village, "village");
    boardDrawer.linkResource(FieldType::Unoccupied, "empty");
    boardDrawer.linkResource(FieldType::City, "city");
    boardDrawer.linkResource(FieldType::Tower, "tower");

    SimpleBoardGenerator boardGenerator;
    boardGenerator.generateBoard(board);
    boardGenerator.assignPlayers(board, playersController);

    UnitsManager unitsManager(boardInfo, textureManager);

    SimpleUnitsPopulator populator("soldier");
    populator.populateBoard(unitsManager, playersController);

    auto cursor = std::make_unique<Cursor>("cursor", Color{100, 200, 50, 255}, board, boardInfo);
    cursor->deduceCursorInitialPosition();

    SoundManager soundManager;
    soundManager.addSound({CursorConsts::rightActionName,
        CursorConsts::leftActionName,
        CursorConsts::upActionName,
        CursorConsts::downActionName}, "sfx/cursor.wav");

    UIManager interfaceManager(textureManager);
    interfaceManager.addElement(std::move(cursor));

    GameLoop loop(unitsManager, board, playersController);

    mapper.addInvokable(&interfaceManager);
    mapper.addInvokable(&soundManager);
    mapper.addInvokable(&loop);
    mapper.mapControl(KEY_UP, CursorConsts::upActionName);
    mapper.mapControl(KEY_DOWN, CursorConsts::downActionName);
    mapper.mapControl(KEY_LEFT, CursorConsts::leftActionName);
    mapper.mapControl(KEY_RIGHT, CursorConsts::rightActionName);
    mapper.mapControl(KEY_ENTER, CursorConsts::endTurnActionName);

    playersController.resetActualPlayer();
    PlayerResourcesManager playerManager(board, *playersController.getActualPlayer());
    auto change = playerManager.calculateResourcesChange();

    auto resourcesUIElement = std::make_unique<ResourcesUIElement>(change, playersController, offsetGUIUp, offsetGUIDown, 12);
    interfaceManager.addElementDrawer(std::move(resourcesUIElement));

    drawingManager.addDrawer(&interfaceManager);
    drawingManager.addDrawer(&boardDrawer);
    drawingManager.addDrawer(&unitsManager);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        mapper.process();
        drawingManager.draw();

        loop.processLogic();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}