#include "Action.h"
#include <iostream>

void Action::execute()
{
	std::cout << "Action " << actionName << " executed." << std::endl;
}
