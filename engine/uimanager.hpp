#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include <vector>
#include <memory>

#include "raylib.h"

#include "iuielement.hpp"
#include "texturemanager.hpp"
#include "iinvokable.hpp"

class UIManager : public IInvokable
{
public:
    UIManager(std::shared_ptr<TextureManager> manager);

    void draw();
    void addElement(std::unique_ptr<IUIElement> element);
    virtual void invokeAction(const std::string& actionName) override;
private:
    std::vector<std::unique_ptr<IUIElement>> _interfaceElements;
    std::shared_ptr<TextureManager> _manager;
};

#endif //UIMANAGER_HPP