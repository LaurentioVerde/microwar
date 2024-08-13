#include "simpleunitspopulator.hpp"

#include "basicunitfactory.hpp"

SimpleUnitsPopulator::SimpleUnitsPopulator(const std::string& basicUnitResourceName):
_basicUnitResourceName(basicUnitResourceName)
{
}

void SimpleUnitsPopulator::populateBoard(UnitsManager& manager, PlayersController& playersController)
{
    if(playersController.getPlayerCount() != getAllowedPlayersCount())
    {
        return;
    }

    playersController.resetActualPlayer();
    BasicUnitFactory unitFactory(_basicUnitResourceName);
    manager.addUnit(unitFactory.produceUnit(std::make_pair(5, 3), playersController.getActualPlayer()));
    playersController.nextPlayer();
    manager.addUnit(unitFactory.produceUnit(std::make_pair(5, 7), playersController.getActualPlayer()));
}

int SimpleUnitsPopulator::getAllowedPlayersCount() const
{
    return 2;
}