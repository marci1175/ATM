#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
int transacionthistory(std::string user_name) {
	std::vector <std::string> lines;
	std::string line;
	std::fstream myFile;
	myFile.open(user_name +".history", std::ios::in | std::ios::out);
	if (myFile.is_open()) {
		while (std::getline(myFile, line)) {
			lines.push_back(line);
		}
		system("CLS");

		int vlenght = lines.size();
		for (size_t i = 0; i < vlenght; i++)
		{
				std::cout << lines[i] << std::endl;
		}
		int fasz;
		std::cout << "Press 0 to exit.";
		std::cin >> fasz;
		system("CLS");
		
	}
	else {
		std::cout << "Error occured!";
		Sleep(3000);
	}



	return 0;
}