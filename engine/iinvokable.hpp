#ifndef IINVOKABLE_HPP
#define IINVOKABLE_HPP

#include <string>

class IInvokable
{
public:
    virtual ~IInvokable() = default;
    virtual void invokeAction(const std::string& actionName) = 0;
};

#endif //IINVOKABLE_HPP
