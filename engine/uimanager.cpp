#include "uimanager.hpp"

#include <algorithm>

UIManager::UIManager(std::shared_ptr<TextureManager> manager):
_manager(manager)
{

}

void UIManager::addElement(std::unique_ptr<IUIElement> element)
{
    _interfaceElements.push_back(std::move(element));
}

void UIManager::addElementDrawer(std::unique_ptr<IUIElementsDrawer> drawer)
{
    _interfaceElementsDrawer.push_back(std::move(drawer));
}

void UIManager::draw()
{
    for(auto& element : _interfaceElements)
    {
        auto position = element->getUIPosition();
        auto resourceName = element->getUIResourceName();
        auto color = element->getColor();

        bool elementDrawn = _manager->drawTexture(resourceName, position.first, position.second, color);
    }
    for(auto& drawer : _interfaceElementsDrawer)
    {
        drawer->draw(*_manager);
    }
}

void UIManager::invokeAction(const std::string& actionName)
{
    for(auto& element : _interfaceElements)
    {
        auto allowedActions = element->getAllowedActions();
        if(std::find(allowedActions.begin(), allowedActions.end(), std::string_view(actionName)) != std::end(allowedActions))
        {
            element->executeAction(actionName);
        }
    }
}
