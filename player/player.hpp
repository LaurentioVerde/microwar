#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "player.hpp"

#include "raylib.h"

#include <memory>
#include <string>

class Player
{
public:
    Player(Color color, const std::string& playerName);
    inline Color getColor() const
    {
        return _color;
    }
    inline std::string getPlayerName() const
    {
        return _playerName;
    }
private:
    Color _color;
    std::string _playerName;
};

#endif //PLAYER_HPP
