#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <string>
#include <memory>

#include "itexturemanager.hpp"

#include "raylib.h"

class TextureManager : public ITextureManager {
public:
    TextureManager();
    virtual ~TextureManager();

    virtual bool addTexture(const std::string& resourceName, std::string resourcePath);
    virtual Texture& getTexture(const std::string& resourceName);
    virtual bool drawTexture(const std::string& resourceName, int x, int y, Color color) override;
private:
    std::map<std::string, Texture> _textures;
};

#endif //TEXTUREMANAGER_HPP