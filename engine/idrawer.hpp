#ifndef IDRAWER_HPP
#define IDRAWER_HPP

class IDrawer {
public:
    virtual ~IDrawer() = default;
    virtual void draw() = 0;
};

#endif //IDRAWER_HPP
