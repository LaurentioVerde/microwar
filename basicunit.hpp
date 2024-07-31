#ifndef BASICUNIT_HPP
#define BASICUNIT_HPP

#include "iunit.hpp"

class BasicUnit : public IUnit
{
public:
    BasicUnit(const std::string& resourceName);
    virtual ~BasicUnit() = default;
    virtual const std::pair<int, int> getPosition() const override;
    virtual void setPosition(std::pair<int, int> position) override;
    virtual Player* getPlayer() const override;
    virtual void setPlayer(Player* player) override;
    virtual const std::string& getUnitResource() const override;
private:
    std::pair<int, int> _position;
    Player* _player;
    std::string _resourceName;
};

#endif //BASICUNIT_HPP