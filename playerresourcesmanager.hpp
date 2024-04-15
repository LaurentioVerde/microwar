#ifndef PLAYERRESOURCESMANAGER_HPP
#define PLAYERRESOURCESMANAGER_HPP

#include "board.hpp"

namespace SimpleGameConsts {
    constexpr int cityActionPointsFactor = 2;
    constexpr int fieldActionPointsFactor = 1;
    constexpr int towerActionPointsFactor = 0;
    constexpr int defaultActionPointsFactor = 0;
}

class PlayerResourcesManager
{
public:
    PlayerResourcesManager(Board& gameBoard, Player& player);

    int calculatePlayerActionPoints() const;
private:
    Board& _board;
    Player& _player;
};

#endif //PLAYERRESOURCESMANAGER_HPP
