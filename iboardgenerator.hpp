#ifndef IBOARDGENERATOR_HPP
#define IBOARDGENERATOR_HPP

#include "board.hpp"

class IBoardGenerator {
public:
    virtual ~IBoardGenerator() = default;
    virtual void generateBoard(Board& board) = 0;
};

#endif //IBOARDGENERATOR_HPP
