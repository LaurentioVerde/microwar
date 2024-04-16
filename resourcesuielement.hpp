#ifndef RESOURCESUIELEMENT_HPP
#define RESOURCESUIELEMENT_HPP

#include "engine/iuielement.hpp"

class ResourcesUIElement : public IUIElement
{
public:
    virtual std::pair<int, int> getUIPosition() const override;
    virtual std::string getUIResourceName() const override;
    virtual Color getColor() const override;
    virtual std::vector<std::string_view> getAllowedActions() const override;
    virtual void executeAction(const std::string& actionName) override;
};

#endif //RESOURCESUIELEMENT_HPP