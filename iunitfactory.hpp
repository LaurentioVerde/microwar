#ifndef IUNITFACTORY_HPP
#define IUNITFACTORY_HPP

#include "iunit.hpp"
#include "player.hpp"

#include <utility>

class IUnitFactory {
public:
    virtual ~IUnitFactory() = default;
    virtual IUnit&& produceUnit(std::pair<int, int> position, Player* player) = 0;
};

#endif //IUNITFACTORY_HPP
