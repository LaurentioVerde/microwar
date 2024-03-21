#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "player.hpp"

#include "raylib.h"

class Player
{
public:
    Player(Color color);
    inline Color getColor() const
    {
        return _color;
    }
private:
    Color _color;
};

#endif //PLAYER_HPP
