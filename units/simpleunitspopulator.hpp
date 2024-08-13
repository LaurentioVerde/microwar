#ifndef SIMPLEUNITSPOPULATOR_HPP
#define SIMPLEUNITSPOPULATOR_HPP

#include "iunitspopulator.hpp"
#include "unitsmanager.hpp"

#include <string>

class SimpleUnitsPopulator : public IUnitsPopulator
{
public:
    SimpleUnitsPopulator(const std::string& basicUnitResourceName);
    virtual void populateBoard(UnitsManager& manager, PlayersController& playersController) override;
    virtual int getAllowedPlayersCount() const override;
private:
    const std::string _basicUnitResourceName;
};

#endif //SIMPLEUNITSPOPULATOR_HPP