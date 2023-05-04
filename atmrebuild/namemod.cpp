#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include "loginpage.h"
int namemod(std::string user_name) {
	std::string newinf;
	std::cout << "Enter your new username : ";
	std::getline(std::cin >> std::ws, newinf);
	const char* newname = newinf.c_str();
	const char* oldname = user_name.c_str();
	int succ = std::rename(oldname, newname);
	system("CLS");
	loginpage(newinf);
	return 0;
}