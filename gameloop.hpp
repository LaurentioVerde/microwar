#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#include "engine/iscenelogic.hpp"
#include "engine/iinvokable.hpp"

#include "unitsmanager.hpp"
#include "board.hpp"
#include "playerscontroller.hpp"

class GameLoop : public ISceneLogic, public IInvokable {
public:
    virtual ~GameLoop() = default;
    GameLoop(UnitsManager& unitsManager, Board& board, PlayersController& playersController);

    virtual void processLogic() override;

    virtual void invokeAction(const std::string& actionName) override;

private:
    void nextPlayer();

private:
    UnitsManager& _unitsManager;
    Board& _board;
    PlayersController& _playersController;
};

#endif //GAMELOOP_HPP
