#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "engine/iuielement.hpp"

#include "board.hpp"
#include "boardinfo.hpp"

#include <utility>
#include <memory>
#include <map>
#include <functional>

namespace CursorConsts {
    static constexpr std::string_view upActionName = "up";
    static constexpr std::string_view downActionName = "down";
    static constexpr std::string_view leftActionName = "left";
    static constexpr std::string_view rightActionName = "right";
    static constexpr std::string_view endTurnActionName = "end";

    static std::vector<std::string_view> actionNames = {upActionName, downActionName,
        leftActionName, rightActionName};
}

class Cursor : public IUIElement
{
public:
    Cursor(std::string resourceName, Color cursorColor, const Board& board, const BoardInfo& info);

    virtual std::pair<int, int> getUIPosition() const override;
    virtual std::string getUIResourceName() const override;
    virtual Color getColor() const override;
    virtual std::vector<std::string_view> getAllowedActions() const override;
    virtual void executeAction(const std::string& actionName) override;

    virtual void deduceCursorInitialPosition();
private:
    void tryUp();
    void tryDown();
    void tryLeft();
    void tryRight();

    void recalculateUIPosition();

private:
    std::string _resourceName;
    Color _color;
    std::pair<int, int> _interfacePosition;
    std::pair<int, int> _position;

    const Board& _board;
    const BoardInfo& _info;
};

#endif //CURSOR_HPP
