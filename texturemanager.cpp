#include "texturemanager.hpp"

#include <stdexcept>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
    for (const auto& [resourceName, texture] : _textures)
    {
        UnloadTexture(texture);
    }
}

bool TextureManager::addTexture(const std::string& resourceName, std::string resourcePath)
{
    if(!_textures.count(resourceName))
    {
        Texture2D newTexture = LoadTexture(resourcePath.c_str());
        _textures[resourceName] = newTexture;
        return true;
    }
    return false;
}

Texture& TextureManager::getTexture(const std::string& resourceName)
{
    return _textures.at(resourceName);
}

bool TextureManager::drawTexture(const std::string& resourceName, int x, int y, Color color)
{
    if(_textures.count(resourceName))
    {
        DrawTexture(_textures[resourceName], x, y, color);
        return true;
    }
    return false;
}
