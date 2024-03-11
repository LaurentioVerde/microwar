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

    board.setBoardData(boardData);
}