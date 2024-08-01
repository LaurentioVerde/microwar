#ifndef IUNITSPOPULATOR_HPP
#define IUNITSPOPULATOR_HPP

#include "unitsmanager.hpp"

class IUnitsPopulator {
public:
    virtual void populateBoard(UnitsManager& manager, std::vector<Player*> players) = 0;
    virtual int getAllowedPlayersCount() const = 0;
};

#endif
