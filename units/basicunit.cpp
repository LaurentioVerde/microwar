#include "basicunit.hpp"

BasicUnit::BasicUnit(const std::string& resourceName):
_position(std::make_pair(0, 0)),
_player(nullptr),
_resourceName(resourceName)
{
}

const std::pair<int, int> BasicUnit::getPosition() const
{
    return _position;
}
void BasicUnit::setPosition(std::pair<int, int> position)
{
    _position = position;
}
Player* BasicUnit::getPlayer() const
{
    return _player;
}
void BasicUnit::setPlayer(Player* player)
{
    _player = player;
}
const std::string& BasicUnit::getUnitResource() const 
{
    return _resourceName;
}
