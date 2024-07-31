#include "basicunitfactory.hpp"

#include "basicunit.hpp"

BasicUnitFactory::BasicUnitFactory(const std::string& unitResourceName):
_unitResourceName(unitResourceName)
{
}

IUnit&& BasicUnitFactory::produceUnit(std::pair<int, int> position, Player* player)
{
    BasicUnit unit(_unitResourceName);
    unit.setPosition(position);
    unit.setPlayer(player);
    return std::move(unit);
}