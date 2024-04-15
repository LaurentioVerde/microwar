#ifndef CONTROLLERMAPPER_HPP
#define CONTROLLERMAPPER_HPP

#include "iinvokable.hpp"
#include <raylib.h>

#include <string>
#include <map>
#include <set>

class ControllerMapper {
public:
    void mapControl(KeyboardKey key, const std::string_view& actionName);
    void addInvokable(IInvokable* invokable);
    void process();
private:
    bool executeAction(KeyboardKey key);
public:
    std::map<KeyboardKey, std::string_view> _controlMap;
    std::set<IInvokable*> _invokable;
};

#endif //CONTROLLERMAPPER_HPP