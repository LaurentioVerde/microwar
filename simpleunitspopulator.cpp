#include "simpleunitspopulator.hpp"

#include "basicunitfactory.hpp"

SimpleUnitsPopulator::SimpleUnitsPopulator(const std::string& basicUnitResourceName):
_basicUnitResourceName(basicUnitResourceName)
{
}

void SimpleUnitsPopulator::populateBoard(UnitsManager& manager, std::vector<Player*> players)
{
    if(players.size() != getAllowedPlayersCount())
    {
        return;
    }

    BasicUnitFactory unitFactory(_basicUnitResourceName);
    manager.addUnit(unitFactory.produceUnit(std::make_pair(5, 3), players[0]));
    manager.addUnit(unitFactory.produceUnit(std::make_pair(5, 7), players[1]));
}

int SimpleUnitsPopulator::getAllowedPlayersCount() const
{
    return 2;
}