#pragma once
#include "Condition.h"
class BoolCondition :
    public Condition
{
public:
    BoolCondition(bool bValueP): Condition(), bValue(bValueP) {}
    virtual bool test();

private:
    bool bValue;
};

