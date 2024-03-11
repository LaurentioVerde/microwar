#ifndef BOARDDRAWER_HPP
#define BOARDDRAWER_HPP

#include <functional>
#include <memory>

#include "board.hpp"
#include "raylib.h"
#include "itexturemanager.hpp"

class BoardDrawer
{
public:
    BoardDrawer(Board& board, std::unique_ptr<ITextureManager> textureManager);
    void draw(const std::string& resourceName, int xOffset, int yOffset);
private:
    Board& _board;
    std::unique_ptr<ITextureManager> _textureManager;
};

#endif //BOARDDRAWER_HPP