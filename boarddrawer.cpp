#include "boarddrawer.hpp"

BoardDrawer::BoardDrawer(Board& board, std::unique_ptr<ITextureManager> textureManager):
_board(board),
_textureManager(std::move(textureManager))
{
}

void BoardDrawer::draw(const std::string& resourceName, int xOffset, int yOffset)
{
    const float tileParam = 24;
    for(int xCounter = 0; xCounter < _board.getBoardWidth(); xCounter++)
    {
        for(int yCounter = 0; yCounter < _board.getBoardHeight(); yCounter++)
        {
            if(_board.getFieldType(std::pair(xCounter, yCounter)) == FieldType::Unoccupied)
            {
                _textureManager->drawTexture(resourceName, (tileParam + 1) * xCounter + xOffset,
                    (tileParam + 1) * yCounter + yOffset);
            }
        }
    }
}
