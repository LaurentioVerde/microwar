#ifndef UNITSMANAGER_HPP
#define UNITSMANAGER_HPP

#include "engine/idrawer.hpp"

class UnitsManager : public IDrawer
{
public:
    virtual ~UnitsManager() = default;
    virtual void draw() override;
};

#endif //PLAYERUNITSPROVIDER_HPP
