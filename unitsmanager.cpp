#include "unitsmanager.hpp"

UnitsManager::UnitsManager(BoardInfo& info, std::shared_ptr<ITextureManager> textureManager):
_info(info),
_textureManager(textureManager)
{
}

void UnitsManager::draw()
{
    for(auto& unit : _units)
    {
        auto resourceName = unit->getUnitResource();
        auto position = unit->getPosition();
        auto color = unit->getPlayer() != nullptr ? unit->getPlayer()->getColor() : WHITE;
        _textureManager->drawTexture(resourceName, (_info.tileSize + 1) * position.first + _info.xOffset,
            (_info.tileSize + 1) * position.second + _info.yOffset, color);
    }
}

void UnitsManager::addUnit(std::unique_ptr<IUnit> unit)
{
    _units.push_back(std::move(unit));
}
