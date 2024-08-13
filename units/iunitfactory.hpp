#ifndef IUNITFACTORY_HPP
#define IUNITFACTORY_HPP

#include "iunit.hpp"
#include "player/player.hpp"

#include <memory>
#include <utility>

class IUnitFactory {
public:
    virtual ~IUnitFactory() = default;
    virtual std::unique_ptr<IUnit> produceUnit(std::pair<int, int> position, Player* player) = 0;
};

#endif //IUNITFACTORY_HPP
