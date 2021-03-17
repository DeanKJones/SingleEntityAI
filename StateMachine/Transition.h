#pragma once
#include <vector>
#include <memory>

#include "Action.h"
#include "Condition.h"

class State;
class Condition;

using std::vector;
using std::shared_ptr;

class Transition
{
public:
	Transition(const Action& actionP, shared_ptr<Condition> conditionP) :
		action(actionP), targetState(nullptr), condition(conditionP) {}

	bool isTriggered() const;
	Action getAction() const;
	shared_ptr<State> getTargetState() const;

	void setTargetState(shared_ptr<State> targetStateP) { targetState = targetStateP; }

private:
	// Same as in State, we keep a copy rather than a ref
	Action action;
	shared_ptr<State> targetState;
	shared_ptr<Condition> condition;
};

