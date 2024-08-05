#include "playerscontroller.hpp"

PlayersController::PlayersController():
_actualPlayer(_players.begin())
{

}

void PlayersController::createPlayer(Color color, const std::string& playerName)
{
    _players.push_back(std::make_unique<Player>(color, playerName));
}

void PlayersController::nextPlayer()
{
    if(_players.size() > 0)
    {
        _actualPlayer++;
        if(_actualPlayer == _players.end())
        {
            _actualPlayer = _players.begin();
        }
    }
}

void PlayersController::resetActualPlayer()
{
    _actualPlayer = _players.begin();
}

const size_t PlayersController::getPlayerCount() const
{
    return _players.size();
}

Player* PlayersController::getActualPlayer() const
{
    if(_actualPlayer != _players.end())
    {
        return _actualPlayer->get();
    }
    else
    {
        return nullptr;
    }
}
