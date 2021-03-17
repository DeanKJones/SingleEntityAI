#include "FloatCondition.h"

bool FloatCondition::test()
{
    return testValue >= minValue && testValue <= maxValue;
}
