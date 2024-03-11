#ifndef SIMPLEBOARDGENERATOR_HPP
#define SIMPLEBOARDGENERATOR_HPP

#include "iboardgenerator.hpp"

class SimpleBoardGenerator : public IBoardGenerator
{
public:
    virtual ~SimpleBoardGenerator() = default;
    virtual void generateBoard(Board& board) override;
};

#endif //SIMPLEBOARDGENERATOR_HPP
