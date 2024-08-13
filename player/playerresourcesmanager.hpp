#ifndef PLAYERRESOURCESMANAGER_HPP
#define PLAYERRESOURCESMANAGER_HPP

#include <vector>

#include "board/board.hpp"
#include "playerresourcesdiff.hpp"

namespace SimpleGameConsts {
    constexpr int cityActionPointsFactor = 2;
    constexpr int villageActionPointsFactor = 1;
    constexpr int towerActionPointsFactor = 0;
    constexpr int defaultActionPointsFactor = 0;

    constexpr int villageFoodBalance = 5;
    constexpr int cityFoodBalance = -7;
    constexpr int towerFoodBalance = -3;
    constexpr int defaultFoodBalance = 0;

    constexpr int villageTaxBalance = 2;
    constexpr int cityTaxBalance = 5;
    constexpr int towerTaxBalance = -5;
    constexpr int defaultTaxBalance = 0;
}

class PlayerResourcesManager
{
public:
    PlayerResourcesManager(Board& gameBoard, Player& player);
    
    PlayerResourcesDiff calculateResourcesChange() const;
private:
    int calculatePlayerActionPoints(const std::vector<FieldType>& fields) const;
    int calculateFoodBalance(const std::vector<FieldType>& fields) const;
    int calculateTaxBalance(const std::vector<FieldType>& fields) const;
private:
    Board& _board;
    Player& _player;
};

#endif //PLAYERRESOURCESMANAGER_HPP
