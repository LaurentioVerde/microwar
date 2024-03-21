#include "board.hpp"

#include <stdexcept>

FieldType Board::getFieldType(std::pair<int, int> coordinates) const
{
    try
    {
        return _boardData.at(coordinates).getFieldType();
    }
    catch(const std::out_of_range& e)
    {
        return FieldType::Empty;
    }   
}

void Board::setFieldToPlayer(std::pair<int, int> coordinates, Player* player)
{
    try
    {
        return _boardData.at(coordinates).setOwner(player);
    }
    catch(const std::out_of_range& e)
    {
        //JUST ABORT
    }
}

Player* Board::getFieldOwner(std::pair<int, int> coordinates) const
{
    try
    {
        return _boardData.at(coordinates).getOwner();
    }
    catch(const std::out_of_range& e)
    {
        return nullptr;
    }   
}
