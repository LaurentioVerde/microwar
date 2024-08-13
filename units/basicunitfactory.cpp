#include "basicunitfactory.hpp"

#include "basicunit.hpp"

BasicUnitFactory::BasicUnitFactory(const std::string& unitResourceName):
_unitResourceName(unitResourceName)
{
}

std::unique_ptr<IUnit> BasicUnitFactory::produceUnit(std::pair<int, int> position, Player* player)
{
    auto unit = std::make_unique<BasicUnit>(_unitResourceName);
    unit->setPosition(position);
    unit->setPlayer(player);
    return std::move(unit);
}