#include "resourcesuielement.hpp"

ResourcesUIElement::ResourcesUIElement(PlayerResourcesDiff& difference, Color color):
_difference(difference),
_color(color)
{
}

Color ResourcesUIElement::getColor() const
{
    return _color;
}

void ResourcesUIElement::draw(TextureManager& manager) const
{
    DrawText("Action points: ", 0, 0, 12, _color);

    for(size_t counter = 0; counter < _difference.actionPointsChange; counter++)
    {
        manager.drawTexture("actionPoint", 85 + counter * 14, 0, _color);
    }
}
