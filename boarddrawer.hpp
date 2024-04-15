#ifndef BOARDDRAWER_HPP
#define BOARDDRAWER_HPP

#include "raylib.h"

#include <functional>
#include <memory>
#include <map>

#include "board.hpp"
#include "boardinfo.hpp"
#include "engine/itexturemanager.hpp"

class BoardDrawer
{
public:
    BoardDrawer(Board& board, BoardInfo& info, std::shared_ptr<ITextureManager> textureManager);
    void draw();
    void linkResource(FieldType fieldType, const std::string& resourceName);
private:
    Board& _board;
    BoardInfo& _info;
    std::shared_ptr<ITextureManager> _textureManager;
    std::map<FieldType, std::string> _resourceLinkage;
};

#endif //BOARDDRAWER_HPP