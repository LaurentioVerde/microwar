#include "gameloop.hpp"

#include "cursor.hpp"

GameLoop::GameLoop(UnitsManager& unitsManager, Board& board, PlayersController& playersController):
_unitsManager(unitsManager),
_board(board),
_playersController(playersController)
{
    _playersController.resetActualPlayer();
}

void GameLoop::processLogic()
{

}

void GameLoop::invokeAction(const std::string& actionName)
{
    if(actionName == CursorConsts::endTurnActionName)
    {
        _playersController.nextPlayer();
    }
}
