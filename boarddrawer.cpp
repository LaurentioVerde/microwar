#include "boarddrawer.hpp"

BoardDrawer::BoardDrawer(Board& board, std::unique_ptr<ITextureManager> textureManager):
_board(board),
_textureManager(std::move(textureManager))
{
}

void BoardDrawer::linkResource(FieldType fieldType, const std::string& resourceName)
{
    _resourceLinkage[fieldType] = resourceName;
}

void BoardDrawer::draw(int xOffset, int yOffset)
{
    const float tileParam = 24;
    for(int xCounter = 0; xCounter < _board.getBoardWidth(); xCounter++)
    {
        for(int yCounter = 0; yCounter < _board.getBoardHeight(); yCounter++)
        {
            auto coordinate = std::pair(xCounter, yCounter);
            auto fieldType = _board.getFieldType(coordinate);
            auto fieldOwner = _board.getFieldOwner(coordinate);
            if(_resourceLinkage.count(fieldType))
            {
                Color color = fieldOwner != nullptr ? fieldOwner->getColor() : WHITE;
                _textureManager->drawTexture(_resourceLinkage[fieldType], (tileParam + 1) * xCounter + xOffset,
                    (tileParam + 1) * yCounter + yOffset, color);
            }
        }
    }
}
