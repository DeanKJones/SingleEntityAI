#include "FloatCondition.h"
#include "Transition.h"
#include "State.h"
#include "StateMachine.h"

#include <memory>
using std::shared_ptr;

void executeActions(vector<Action>& actions) {
	for (auto& action : actions) {
		action.execute();
	}
}

int main() {
	// Condition will be stored as a shared pointer, for we want to use
	// The same condition for every transition instance.
	// We could also create a unique condition (with a unique pointer) for
	// each transition, but we would need 4 instances.
	// (See below for std::make_shared.)
	auto cond = std::make_shared<FloatCondition>(1.0f, 2.0f, 1.5f);

	Action seeBigEnemyAction("I'm seeing a big enemy");
	Action seeSmallEnemyAction("I'm seeing a small enemy");
	Action losingFightAction("I'm losing my fight");
	Action escapedAction("Phew! I escaped.");

	// Here I store my transitions with a shared pointer.
	// std::make_shared is a function that calls a constructor to generate a pointer.
	// In this case, I call the 2 parameters constructors
	auto seeBigEnemyTransition(std::make_shared<Transition>(seeBigEnemyAction, cond));
	auto seeSmallEnemyTransition(std::make_shared<Transition>(seeSmallEnemyAction, cond));
	auto losingFightTransition(std::make_shared<Transition>(losingFightAction, cond));
	auto escapedTransition(std::make_shared<Transition>(escapedAction, cond));

	Action onGuardEntryAction("I'm entering Guard state");
	Action onGuardAction("I'm in Guard state");
	Action onGuardExitAction("I'm exiting Guard state");
	Action fightEntryAction("I'm entering Fight state");
	Action fightAction("I'm in Fight state");
	Action fightExitAction("I'm exiting Fight state");

	// I pass my vector of shared pointers by copy, which add a new element into the pointer count
	auto guardTransitions = vector<shared_ptr<Transition>>{ seeSmallEnemyTransition };
	State onGuardState(onGuardAction, onGuardEntryAction, onGuardExitAction, guardTransitions);
	State fightState(fightAction, fightEntryAction, fightExitAction, vector<shared_ptr<Transition>> {});
	
	// For transition's target state, I create the shared pointer on the fly, 
	// so it is stored in the transition. The make_shared parameter is built and deleted immediatly.
	// I could use a rvalue instead of a copy, but this is advanced.
	seeSmallEnemyTransition->setTargetState(std::make_shared<State>(fightState));

	StateMachine machine(onGuardState);
	vector<Action> actions = machine.update();
	executeActions(actions);
	actions = machine.update();
	executeActions(actions);

	return 0;
}