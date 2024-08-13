#include "playerresourcesmanager.hpp"

#include <vector>

PlayerResourcesManager::PlayerResourcesManager(Board& gameBoard, Player& player):
_board(gameBoard),
_player(player)
{
}

PlayerResourcesDiff PlayerResourcesManager::calculateResourcesChange() const
{
    std::vector<FieldType> fields;
    for(size_t counterX = 0; counterX < _board.getBoardWidth(); counterX++)
    {
        for(size_t counterY = 0; counterY < _board.getBoardHeight(); counterY++)
        {
            std::pair<int, int> location = {counterX, counterY};
            if(_board.getFieldOwner(location) == &_player)
            {
                fields.push_back(_board.getFieldType(location));
            }
        }
    }

    PlayerResourcesDiff diff = {.actionPointsChange = calculatePlayerActionPoints(fields),
        .taxBalance = calculateTaxBalance(fields),
        .foodBalance = calculateFoodBalance(fields)};

    return diff;
}

int PlayerResourcesManager::calculatePlayerActionPoints(const std::vector<FieldType>& fields) const
{
    int points = 0;

    for(const auto& fieldType : fields)
    {            
        switch(fieldType)
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

    return points;
}

int PlayerResourcesManager::calculateFoodBalance(const std::vector<FieldType>& fields) const
{
    int balance = 0;

    for(const auto& fieldType : fields)
    {            
        switch(fieldType)
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

    return balance;
}

int PlayerResourcesManager::calculateTaxBalance(const std::vector<FieldType>& fields) const
{
    int tax = 0;

    for(const auto& fieldType : fields)
    {            
        switch(fieldType)
        {
            case FieldType::Tower:
                tax += SimpleGameConsts::towerTaxBalance;
                break;
            case FieldType::Village:
                tax += SimpleGameConsts::villageTaxBalance;
                break;
            case FieldType::City:
                tax += SimpleGameConsts::cityTaxBalance;
                break;
            default:
                tax += SimpleGameConsts::defaultTaxBalance;
                break;
        }
    }

    return tax;
}
