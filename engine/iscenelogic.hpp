#ifndef ISCENELOGIC_HPP
#define ISCENELOGIC_HPP

class ISceneLogic
{
public:
    virtual ~ISceneLogic() = default;
    virtual void processLogic() = 0;
};

#endif //ISCENELOGIC_HPP
