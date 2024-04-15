#include "playerresourcesmanager.hpp"

#include <vector>

PlayerResourcesManager::PlayerResourcesManager(Board& gameBoard, Player& player):
_board(gameBoard),
_player(player)
{
}

int PlayerResourcesManager::calculatePlayerActionPoints() const
{
    int points = 0;

    std::vector<Field> fields;
    for(size_t counterX = 0; counterX < _board.getBoardWidth(); counterX++)
    {
        for(size_t counterY = 0; counterY < _board.getBoardHeight(); counterY++)
        {
            std::pair<int, int> location = {counterX, counterY};
            if(_board.getFieldOwner(location) == &_player)
            {
                switch(_board.getFieldType(location))
                {
                    case FieldType::Tower:
                        points += SimpleGameConsts::towerActionPointsFactor;
                        break;
                    case FieldType::Village:
                        points += SimpleGameConsts::villageActionPointsFactor;
                        break;
                    case FieldType::City:
                        points += SimpleGameConsts::cityActionPointsFactor;
                        break;
                    default:
                        points += SimpleGameConsts::defaultActionPointsFactor;
                        break;
                }
            }
        }
    }

    return points;
}

int PlayerResourcesManager::calculateFoodBalance() const
{
    int balance = 0;

    std::vector<Field> fields;
    for(size_t counterX = 0; counterX < _board.getBoardWidth(); counterX++)
    {
        for(size_t counterY = 0; counterY < _board.getBoardHeight(); counterY++)
        {
            std::pair<int, int> location = {counterX, counterY};
            if(_board.getFieldOwner(location) == &_player)
            {
                switch(_board.getFieldType(location))
                {
                    case FieldType::Tower:
                        balance += SimpleGameConsts::towerFoodBalance;
                        break;
                    case FieldType::Village:
                        balance += SimpleGameConsts::villageFoodBalance;
                        break;
                    case FieldType::City:
                        balance += SimpleGameConsts::cityFoodBalance;
                        break;
                    default:
                        balance += SimpleGameConsts::defaultFoodBalance;
                        break;
                }
            }
        }
    }

    return balance;
}
