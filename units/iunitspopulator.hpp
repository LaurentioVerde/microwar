#ifndef IUNITSPOPULATOR_HPP
#define IUNITSPOPULATOR_HPP

#include "unitsmanager.hpp"
#include "player/playerscontroller.hpp"

class IUnitsPopulator {
public:
    virtual void populateBoard(UnitsManager& manager, PlayersController& playersController) = 0;
    virtual int getAllowedPlayersCount() const = 0;
};

#endif
