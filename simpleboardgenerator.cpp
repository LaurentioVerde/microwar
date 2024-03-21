#include "simpleboardgenerator.hpp"
#include "field.hpp"
#include "fieldtype.hpp"

#include <vector>
#include <cmath>

void SimpleBoardGenerator::generateBoard(Board& board)
{
    const size_t width = 11;
    const size_t height = 11;
    const std::vector<int> halfboardGenerationScheme = {3, 5, 7, 9, 11, 11, 11, 9, 7, 5, 3};

    board.setBoardWidth(width);
    board.setBoardHeight(height);

    std::map<std::pair<int, int>, Field> boardData;

    for(int counterY = 0; counterY < height; counterY++)
    {
        auto min = floor(height / 2) - floor(halfboardGenerationScheme[counterY] / 2);
        auto max = floor(height / 2) + floor(halfboardGenerationScheme[counterY] / 2);
        for(int counterX = 0; counterX < width; counterX++)
        {
            Field field;
            field.setFieldType(counterX >= min && counterX <= max ? FieldType::Unoccupied : FieldType::Empty);
            boardData[std::pair(counterX, counterY)] = field;
        }
    }

    boardData[std::pair(4, 0)].setFieldType(FieldType::Village);
    boardData[std::pair(5, 0)].setFieldType(FieldType::City);
    boardData[std::pair(6, 0)].setFieldType(FieldType::Village);
    boardData[std::pair(5, 2)].setFieldType(FieldType::Tower);

    boardData[std::pair(4, 10)].setFieldType(FieldType::Village);
    boardData[std::pair(5, 10)].setFieldType(FieldType::City);
    boardData[std::pair(6, 10)].setFieldType(FieldType::Village);
    boardData[std::pair(5, 8)].setFieldType(FieldType::Tower);

    board.setBoardData(boardData);
}

void SimpleBoardGenerator::assignPlayers(Board &board, std::vector<Player*> players)
{
    if(players.size() != getAllowedPlayersCount())
    {
        return;
    }

    board.setFieldToPlayer(std::pair(4, 0), players[0]);
    board.setFieldToPlayer(std::pair(5, 0), players[0]);
    board.setFieldToPlayer(std::pair(6, 0), players[0]);
    board.setFieldToPlayer(std::pair(5, 2), players[0]);

    board.setFieldToPlayer(std::pair(4, 10), players[1]);
    board.setFieldToPlayer(std::pair(5, 10), players[1]);
    board.setFieldToPlayer(std::pair(6, 10), players[1]);
    board.setFieldToPlayer(std::pair(5, 8), players[1]);
}
