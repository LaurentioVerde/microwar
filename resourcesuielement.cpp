#include "resourcesuielement.hpp"

ResourcesUIElement::ResourcesUIElement(PlayerResourcesDiff& difference, Color color,
    std::pair<int, int> offsetUp, std::pair<int, int> offsetDown, int fontSize):
_difference(difference),
_color(color),
_offsetDown(offsetDown),
_offsetUp(offsetUp),
_fontSize(fontSize)
{
}

Color ResourcesUIElement::getColor() const
{
    return _color;
}

void ResourcesUIElement::draw(TextureManager& manager) const
{
    DrawText("Action points: ", _offsetUp.first, _offsetUp.second, _fontSize, _color);

    for(size_t counter = 0; counter < _difference.actionPointsChange; counter++)
    {
        manager.drawTexture("actionPoint", _offsetUp.first + 85 + counter * 14, _offsetUp.second, _color);
    }

    std::string foodBalanceText = "";
    if(_difference.foodBalance <= 0)
    {
        foodBalanceText += std::to_string(_difference.foodBalance);
    }
    else
    {
        foodBalanceText += "+" + std::to_string(_difference.foodBalance);
    }

    DrawText(foodBalanceText.c_str(), _offsetDown.first, _offsetDown.second, _fontSize, _color);
    manager.drawTexture("foodIcon", _offsetDown.first + 10, _offsetDown.second, _color);

    std::string taxBalanceText = "";
    if(_difference.taxBalance <= 0)
    {
        taxBalanceText += std::to_string(_difference.taxBalance);
    }
    else
    {
        taxBalanceText += "+" + std::to_string(_difference.taxBalance);
    }

    DrawText(taxBalanceText.c_str(), _offsetDown.first + 30, _offsetDown.second, _fontSize, _color);
    manager.drawTexture("taxIcon", _offsetDown.first + 45, _offsetDown.second, _color);
}
