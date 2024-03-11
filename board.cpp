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