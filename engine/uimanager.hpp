#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include <vector>
#include <memory>

#include "raylib.h"

#include "iuielement.hpp"
#include "texturemanager.hpp"
#include "iinvokable.hpp"
#include "iuielementsdrawer.hpp"

class UIManager : public IInvokable
{
public:
    UIManager(std::shared_ptr<TextureManager> manager);

    void draw();
    void addElementDrawer(std::unique_ptr<IUIElementsDrawer> drawer);
    void addElement(std::unique_ptr<IUIElement> element);
    virtual void invokeAction(const std::string& actionName) override;
private:
    std::vector<std::unique_ptr<IUIElement>> _interfaceElements;
    std::vector<std::unique_ptr<IUIElementsDrawer>> _interfaceElementsDrawer;
    std::shared_ptr<TextureManager> _manager;
};

#endif //UIMANAGER_HPP