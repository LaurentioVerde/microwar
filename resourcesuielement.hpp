#ifndef RESOURCESUIELEMENT_HPP
#define RESOURCESUIELEMENT_HPP

#include "engine/iuielementsdrawer.hpp"
#include "playerresourcesdiff.hpp"

class ResourcesUIElement : public IUIElementsDrawer
{
public:
    ResourcesUIElement(PlayerResourcesDiff& difference, Color color);

    virtual Color getColor() const override;
    virtual void draw(TextureManager& manager) const override;

private:
    PlayerResourcesDiff _difference;
    Color _color;
};

#endif //RESOURCESUIELEMENT_HPP