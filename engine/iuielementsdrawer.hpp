#ifndef IUIELEMENTDRAWER_HPP
#define IUIELEMENTDRAWER_HPP

#include "raylib.h"
#include "texturemanager.hpp"

class IUIElementsDrawer {
public:
    virtual ~IUIElementsDrawer() = default;
    virtual Color getColor() const = 0;
    virtual void draw(TextureManager& manager) const = 0;
};

#endif //IUIELEMENT_HPP
