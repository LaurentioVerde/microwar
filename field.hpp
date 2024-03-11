#ifndef FIELD_HPP
#define FIELD_HPP

#include "player.hpp"
#include "fieldtype.hpp"

class Field
{
public:
    inline void setOwner(Player *owner)
    {
        _owner = owner;
    }
    inline Player* getOwner() const
    {
        return _owner;
    }
    inline void setFieldType(FieldType fieldType)
    {
        _fieldType = fieldType;
    }
    inline FieldType getFieldType() const
    {
        return _fieldType;
    }
private:
    Player *_owner;
    FieldType _fieldType;
};

#endif //FIELD_HPP