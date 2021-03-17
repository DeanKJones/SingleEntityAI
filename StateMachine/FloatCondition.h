#pragma once
#include "Condition.h"
class FloatCondition : public Condition
{
public:
    FloatCondition(float minValueP, float maxValueP, float testValueP) :
        Condition(), minValue(minValueP), maxValue(maxValueP), testValue(testValueP)
    {}

    virtual bool test();


private:
    float minValue;
    float maxValue;
    float testValue;
};

