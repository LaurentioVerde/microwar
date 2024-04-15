#ifndef ITEXTUREMANAGER_HPP
#define ITEXTUREMANAGER_HPP

#include <string>

#include "raylib.h"

class ITextureManager
{
public:
    virtual ~ITextureManager() = default;
    virtual bool drawTexture(const std::string& resourceName, int x, int y, Color color) = 0;
};

#endif //ITEXTUREMANAGER_HPP