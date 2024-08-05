#ifndef PLAYERSCONTROLLER_HPP
#define PLAYERSCONTROLLER_HPP

#include <vector>
#include <memory>

#include "player.hpp"
#include "raylib.h"

class PlayersController
{
public:
    PlayersController();
    virtual ~PlayersController() = default;
    void createPlayer(Color color, const std::string& playerName);
    void nextPlayer();
    void resetActualPlayer();
    const size_t getPlayerCount() const;
    Player* getActualPlayer() const;

private:
    std::vector<std::unique_ptr<Player>> _players;
    std::vector<std::unique_ptr<Player>>::iterator _actualPlayer;
};

#endif //PLAYERSCONTROLLER_HPP
