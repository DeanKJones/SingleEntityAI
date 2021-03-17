#pragma once
#include <vector>
#include <memory>
using std::shared_ptr;

#include "Action.h"
#include "Transition.h"

using std::vector;

class State
{
public:
	State(const Action& stateActionP, const Action& entryActionP, const Action& exitActionP, vector<shared_ptr<Transition>> transitionsP):
		stateAction(stateActionP), entryAction(entryActionP), exitAction(exitActionP), transitions(transitionsP)
	{}

	Action getAction() const { return stateAction; }
	Action getEntryAction() const { return entryAction; }
	Action getExitAction() const { return exitAction; }
	const vector<shared_ptr<Transition>>& getTransitions() const { return transitions; }

private:
	vector<shared_ptr<Transition>> transitions;

	// Those actions are copies, which seems legit
	Action stateAction;
	Action entryAction;
	Action exitAction;
};

