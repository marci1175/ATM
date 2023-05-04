#include <iostream>
#include "main.h"
#include "login.h"
#include "regstr.h"
int actionhandler(int action)
{

	switch (action)
	{
	case 0:
		break;
	case 1:
		regstr();
		main();
		break;
	case 2:
		login();
		system("CLS");
		main();
		break;
	default:
		system("CLS");
		std::cout << "[You have entered an invalid number, please coose from the available ones!]\n---------------------------------------------------------------------------\n\n";
		main();
		break;
	}



	return 0;
}