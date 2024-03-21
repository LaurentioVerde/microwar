#ifndef BOARDDRAWER_HPP
#define BOARDDRAWER_HPP

#include <functional>
#include <memory>
#include <map>

#include "board.hpp"
#include "raylib.h"
#include "itexturemanager.hpp"

class BoardDrawer
{
public:
    BoardDrawer(Board& board, std::unique_ptr<ITextureManager> textureManager);
    void draw(int xOffset, int yOffset);
    void linkResource(FieldType fieldType, const std::string& resourceName);
private:
    Board& _board;
    std::unique_ptr<ITextureManager> _textureManager;
    std::map<FieldType, std::string> _resourceLinkage;
};

#endif //BOARDDRAWER_HPP