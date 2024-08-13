#ifndef IUNIT_HPP
#define IUNIT_HPP

#include <utility>
#include <string> 

#include "player/player.hpp"

class IUnit
{
public:
    virtual ~IUnit() = default;
    virtual const std::pair<int, int> getPosition() const = 0;
    virtual void setPosition(std::pair<int, int> position) = 0;
    virtual Player* getPlayer() const = 0;
    virtual void setPlayer(Player* player) = 0;
    virtual const std::string& getUnitResource() const = 0;
};

#endif //IUNIT_HPP