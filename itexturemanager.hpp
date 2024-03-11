#ifndef ITEXTUREMANAGER_HPP
#define ITEXTUREMANAGER_HPP

#include <string>

class ITextureManager
{
public:
    virtual ~ITextureManager() = default;
    virtual bool drawTexture(const std::string& resourceName, int x, int y) = 0;
};

#endif //ITEXTUREMANAGER_HPP