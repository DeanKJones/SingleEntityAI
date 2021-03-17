#pragma once
#include <string>

using std::string;

class Action
{
public:
	Action(string actionNameP) : actionName(actionNameP) {}
	void execute();

private:
	string actionName;
};

