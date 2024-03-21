#ifndef SIMPLEBOARDGENERATOR_HPP
#define SIMPLEBOARDGENERATOR_HPP

#include "iboardgenerator.hpp"

class SimpleBoardGenerator : public IBoardGenerator
{
public:
    virtual ~SimpleBoardGenerator() = default;
    virtual void generateBoard(Board& board) override;
    virtual void assignPlayers(Board &board, std::vector<Player*> players) override;

    virtual inline int getAllowedPlayersCount() const override
    {
        return 2;
    }
};

#endif //SIMPLEBOARDGENERATOR_HPP
