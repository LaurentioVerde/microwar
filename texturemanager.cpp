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
        _textures[resourceName] = LoadTexture(resourcePath.c_str());
        return true;
    }
    return false;
}

Texture& TextureManager::getTexture(const std::string& resourceName)
{
    return _textures.at(resourceName);
}

bool TextureManager::drawTexture(const std::string& resourceName, int x, int y)
{
    if(!_textures.count(resourceName))
    {
        DrawTexture(_textures[resourceName], x, y, WHITE);
        return true;
    }
    return false;
}
