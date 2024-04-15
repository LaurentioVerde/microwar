#include "boarddrawer.hpp"

BoardDrawer::BoardDrawer(Board& board, BoardInfo& info, std::shared_ptr<ITextureManager> textureManager):
_board(board),
_info(info),
_textureManager(std::move(textureManager))
{
}

void BoardDrawer::linkResource(FieldType fieldType, const std::string& resourceName)
{
    _resourceLinkage[fieldType] = resourceName;
}

void BoardDrawer::draw()
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
                _textureManager->drawTexture(_resourceLinkage[fieldType], (_info.tileSize + 1) * xCounter + _info.xOffset,
                    (_info.tileSize + 1) * yCounter + _info.yOffset, color);
            }
        }
    }
}
