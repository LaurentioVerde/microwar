#include "drawingmanager.hpp"

void DrawingManager::addDrawer(IDrawer* drawer)
{
    _drawers.push_back(drawer);
}

void DrawingManager::draw()
{
    for(auto& drawer : _drawers)
    {
        drawer->draw();
    }
}
