#ifndef DRAWINGMANAGER_HPP
#define DRAWINGMANAGER_HPP

#include "idrawer.hpp"

#include <vector>

class DrawingManager {
public:
    void addDrawer(IDrawer* drawer);
    void draw();
private:
    std::vector<IDrawer*> _drawers;
};

#endif //DRAWINGMANAGER_HPP
