#ifndef BOARD_HPP
#define BOARD_HPP

#include <map>
#include <algorithm>

#include "field.hpp"

class Board
{
public:
    inline void setBoardData(std::map<std::pair<int, int>, Field> boardData)
    {
        _boardData = boardData;
    }
    inline void setBoardWidth(unsigned int width)
    {
        _width = width;
    }
    inline unsigned int getBoardWidth() const
    {
        return _width;
    }
    inline void setBoardHeight(unsigned int height)
    {
        _height = height;
    }
    inline unsigned int getBoardHeight() const
    {
        return _height;
    }

    FieldType getFieldType(std::pair<int, int> coordinates) const;

    void setFieldToPlayer(std::pair<int, int> coordinates, Player* player);
    Player* getFieldOwner(std::pair<int, int> coordinates) const;
private:
    std::map<std::pair<int, int>, Field> _boardData;
    unsigned int _width;
    unsigned int _height;
};

#endif //BOARD_HPP
