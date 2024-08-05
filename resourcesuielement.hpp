#ifndef RESOURCESUIELEMENT_HPP
#define RESOURCESUIELEMENT_HPP

#include "engine/iuielementsdrawer.hpp"
#include "playerresourcesdiff.hpp"
#include "playerscontroller.hpp"

class ResourcesUIElement : public IUIElementsDrawer
{
public:
    ResourcesUIElement(PlayerResourcesDiff& difference, PlayersController& playersController,
        std::pair<int, int> offsetUp, std::pair<int, int> offsetDown, int fontSize);

    virtual Color getColor() const override;
    virtual void draw(TextureManager& manager) const override;
    
private:
    PlayerResourcesDiff& _difference;
    PlayersController& _playersController;
    Color* _colorSource;
    const std::pair<int, int> _offsetUp;
    const std::pair<int, int> _offsetDown;
    int _fontSize;
};

#endif //RESOURCESUIELEMENT_HPP