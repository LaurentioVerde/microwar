#include "controllermapper.hpp"

void ControllerMapper::mapControl(KeyboardKey key, const std::string_view& actionName)
{
    _controlMap[key] = actionName;
}

void ControllerMapper::addInvokable(IInvokable* invokable)
{
    _invokable.insert(invokable);
}

bool ControllerMapper::executeAction(KeyboardKey key)
{
    if(_controlMap.count(key) > 0)
    {
        const std::string actionName = std::string(_controlMap[key]);
        for(auto& invokable : _invokable)
        {
            invokable->invokeAction(actionName);
        }
        return true;
    }
    return false;
}

void ControllerMapper::process()
{
    KeyboardKey key = KEY_NULL;
    do
    {
        key = static_cast<KeyboardKey>(GetKeyPressed());
        if(key != KEY_NULL)
        {
            executeAction(key);
        }
    } while(key != KEY_NULL);
}
