#ifndef BASICUNITFACTORY_HPP
#define BASICUNITFACTORY_HPP

#include "iunitfactory.hpp"

class BasicUnitFactory : public IUnitFactory {
public:
    BasicUnitFactory(const std::string& unitResourceName);
    virtual ~BasicUnitFactory() = default;
    virtual IUnit&& produceUnit(std::pair<int, int> position, Player* player) override;
private:
    const std::string _unitResourceName;
};

#endif //BASICUNITFACTORY_HPP
