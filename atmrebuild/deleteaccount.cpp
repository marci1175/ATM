#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "loginpage.h"
int deleteaccount(std::string user_name){
	std::fstream myFile;
	myFile.open(user_name, std::ios::in | std::ios::out);
	std::string file_tartalom;
	std::vector <std::string> file_vector;
	while (std::getline(myFile, file_tartalom)) {
		file_vector.push_back(file_tartalom);
	}
	myFile.flush();
	myFile.close();

	std::string real_name; std::string passwo; std::string regtime;
	int bank_id; int card_id; int balance;


	real_name = file_vector[0];
	passwo = file_vector[1];
	bank_id = stoi(file_vector[2]);
	card_id = stoi(file_vector[3]);
	balance = stoi(file_vector[4]);
	regtime = file_vector[5];

	std::cout << "Enter your password!:\n";
	std::string usrpass;
	std::getline(std::cin >> std::ws, usrpass);
	if (usrpass == passwo) {
		char fileName[20];
		std::cout << "Enter your username : ";
		std::cin >> fileName;
		if (fileName == user_name) {
			
			int stat = remove(fileName);
			if (stat == -1) {
				perror("Error: ");
				Sleep(3000);
			}
		}
		else {
			system("CLS");
			std::cout << "You cannot remove someone else's account!";
			Sleep(3000);
			system("CLS");
			
			loginpage(user_name);
		}
	}
	else {
		system("CLS");
		std::cout << "Incorrect password!";
		Sleep(3000);
		system("CLS");
		loginpage(user_name);
	}
	
	
	
	
	return 0;
}