#include "Transition.h"
#include "State.h"

bool Transition::isTriggered() const
{
	return condition->test();
}

Action Transition::getAction() const
{
	return action;
}

shared_ptr<State> Transition::getTargetState() const
{
	return targetState;
}
