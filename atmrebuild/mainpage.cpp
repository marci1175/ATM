#include <iostream>
#include "actionhandler.h"
int main()
{
	std::cout << "Welcome to marci#1175's ATM!\n";
	std::cout << "Please enter an action from below: \n\n		[0) Exit]\n\n		1) Register\n		2) Login\n		3) [PLACEHOLDER]\n\n|:";
	int action;
	std::cin >> action;
	actionhandler(action);
}