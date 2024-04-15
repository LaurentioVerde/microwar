#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP

#include "raylib.h"

#include "iinvokable.hpp"

#include <string>
#include <vector>
#include <map>

class SoundManager : public IInvokable
{
public:
    void addSound(const std::string_view& actionName, std::string resourcePath);
    void addSound(std::vector<std::string_view> actionNames, std::string resourcePath);

    virtual void invokeAction(const std::string& actionName) override;
private:
    std::map<std::string_view, Sound> _soundMapper;
};

#endif //SOUNDMANAGER_HPP
