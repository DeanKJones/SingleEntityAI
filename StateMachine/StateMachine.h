#pragma once
#include <vector>
#include "State.h"

class Action;
using std::vector;

class StateMachine
{
public:
	StateMachine(State& initialStateP) : currentState(initialStateP) {}
	vector<Action> update();

private:
	// We should use this in real cases. We can populate
	// it by adding states through a public function.
	vector<State> states;

	// This is a reference, for it should exist in
	// the states vector or in main.
	State& currentState;
};
