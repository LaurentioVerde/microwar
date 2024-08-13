#ifndef IBOARDGENERATOR_HPP
#define IBOARDGENERATOR_HPP

#include "board.hpp"
#include "player/playerscontroller.hpp"

#include <vector>

class IBoardGenerator {
public:
    virtual ~IBoardGenerator() = default;
    virtual void generateBoard(Board& board) = 0;
    virtual int getAllowedPlayersCount() const = 0;
    virtual void assignPlayers(Board &board, PlayersController &playersController) = 0;
};

#endif //IBOARDGENERATOR_HPP
