#ifndef UNITSMANAGER_HPP
#define UNITSMANAGER_HPP

#include "engine/idrawer.hpp"
#include "engine/itexturemanager.hpp"

#include "iunit.hpp"
#include "boardinfo.hpp"

#include <vector>
#include <memory>

class UnitsManager : public IDrawer
{
public:
    UnitsManager(BoardInfo& info, std::shared_ptr<ITextureManager> textureManager);
    virtual ~UnitsManager() = default;
    virtual void draw() override;
    virtual void addUnit(std::unique_ptr<IUnit> unit);
private:
    BoardInfo& _info;
    std::shared_ptr<ITextureManager> _textureManager;
    std::vector<std::unique_ptr<IUnit>> _units;
};

#endif //PLAYERUNITSPROVIDER_HPP
