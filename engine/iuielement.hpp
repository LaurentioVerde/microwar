#ifndef IUIELEMENT_HPP
#define IUIELEMENT_HPP

#include <utility>
#include <string>
#include <vector>

#include "raylib.h"

class IUIElement {
public:
    virtual ~IUIElement() = default;
    virtual std::pair<int, int> getUIPosition() const = 0;
    virtual std::string getUIResourceName() const = 0;
    virtual Color getColor() const = 0;
    virtual std::vector<std::string_view> getAllowedActions() const = 0;
    virtual void executeAction(const std::string& actionName) = 0;
};

#endif //IUIELEMENT_HPP
