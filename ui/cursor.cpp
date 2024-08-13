#include "cursor.hpp"

#include "core/consts.hpp"

Cursor::Cursor(std::string resourceName, Color cursorColor, const Board& board, const BoardInfo& info):
_resourceName(resourceName),
_color(cursorColor),
_interfacePosition(0, 0),
_board(board),
_info(info)
{
}

std::pair<int, int> Cursor::getUIPosition() const
{
    return _interfacePosition;
}
std::string Cursor::getUIResourceName() const
{
    return _resourceName;
}
Color Cursor::getColor() const
{
    return _color;
}

std::vector<std::string_view> Cursor::getAllowedActions() const
{
    return CursorConsts::actionNames;
}

void Cursor::executeAction(const std::string& actionName)
{
    if(actionName == CursorConsts::downActionName)
    {
        tryDown();
    }
    else if(actionName == CursorConsts::upActionName)
    {
        tryUp();
    }
    else if(actionName == CursorConsts::leftActionName)
    {
        tryLeft();
    }
    else if(actionName == CursorConsts::rightActionName)
    {
        tryRight();
    }

    recalculateUIPosition();
}


void Cursor::deduceCursorInitialPosition()
{
    auto height = _board.getBoardHeight();
    auto width = _board.getBoardWidth();

    _position.first = (width / 2);
    _position.second = (height / 2);

    recalculateUIPosition();
}

void Cursor::tryUp()
{
    std::pair<int, int> newPosition {_position.first, _position.second - 1};
    auto fieldType = _board.getFieldType(newPosition);
    if(fieldType != FieldType::Empty)
    {
        _position = newPosition;
    }
}

void Cursor::tryDown()
{
    std::pair<int, int> newPosition {_position.first, _position.second + 1};
    auto fieldType = _board.getFieldType(newPosition);
    if(fieldType != FieldType::Empty)
    {
        _position = newPosition;
    }
}


void Cursor::tryLeft()
{
    std::pair<int, int> newPosition {_position.first - 1, _position.second};
    auto fieldType = _board.getFieldType(newPosition);
    if(fieldType != FieldType::Empty)
    {
        _position = newPosition;
    }
}

void Cursor::tryRight()
{
    std::pair<int, int> newPosition {_position.first + 1, _position.second};
    auto fieldType = _board.getFieldType(newPosition);
    if(fieldType != FieldType::Empty)
    {
        _position = newPosition;
    }
}

void Cursor::recalculateUIPosition()
{
    if(_position.first >= 0 && _position.second >= 0)
    {
        _interfacePosition.first = _info.xOffset + _position.first * (_info.tileSize + 1);
        _interfacePosition.second = _info.yOffset + _position.second * (_info.tileSize + 1);
    }
}
