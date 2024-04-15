#include "soundmanager.hpp"

void SoundManager::addSound(const std::string_view& actionName, std::string resourcePath)
{
    auto sound = LoadSound(resourcePath.c_str());
    _soundMapper[actionName] = sound;
}

void SoundManager::addSound(std::vector<std::string_view> actionNames, std::string resourcePath)
{
    auto sound = LoadSound(resourcePath.c_str());
    for(const auto& actionName : actionNames)
    {
        _soundMapper[actionName] = sound;
    }
}

void SoundManager::invokeAction(const std::string& actionName)
{
    for(auto& [key, value] : _soundMapper)
    {
        if(key == actionName)
        {
            PlaySound(value);
            return;
        }
    }
}
