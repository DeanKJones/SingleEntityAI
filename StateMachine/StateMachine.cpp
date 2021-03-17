#include "StateMachine.h"
#include "Transition.h"

#include <memory>
using std::shared_ptr;

vector<Action> StateMachine::update()
{
    // Check if there is a triggered transition
    shared_ptr<Transition> triggeredTransition = nullptr;

    for (auto& transition : currentState.getTransitions()) {
        if (transition->isTriggered()) {
            triggeredTransition = transition;
        }
    }

    if (triggeredTransition != nullptr) {
        // This shared pointer only exist during the function execution
        shared_ptr<State> targetState = triggeredTransition->getTargetState();

        vector<Action> actions{
            currentState.getExitAction(),
            triggeredTransition->getAction(),
            targetState->getEntryAction()
        };

        // I store a reference, for it is more elegant than
        // a shared pointer. And it is assured to be not null.
        currentState = *targetState;
        return actions;
    }

    return vector<Action> { currentState.getAction() };
}
