#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//account actions

#include "loginpageactionhandler.h"

int loginpage(std::string user_name) {
	std::cout << "Logged in as " << user_name << " !\n";
	std::cout << "Please enter an action from below: \n[--------------------------------------------------------]\n\n			[0) Logout]\n\n[--------------------------------------------------------]\n\n		1) Deposit money\n		2) Withdraw money\n		3) Send money\n		4) View transaction history\n		5) Change account credentials\n		6) Delete account\n";
	
	
	
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
	if (file_vector.size() == 0) {
		std::cout << "\n\n\nCritical error occured!\nFile not found\n";
	}
	std::cout << "\n\n[--------------------------------------------------------]\n" << "		   Account Info:\n" << "	Account owner : " << real_name << "\n	Account number : " << bank_id <<"\n	Credit card number : " << card_id<< "\n	Balance : " << balance<<"$" << "\n	Regitration date : " << regtime << "\n[--------------------------------------------------------]" << std::endl;
	std::cout << "\n|:";
	
	
	int user_login_action;
	std::cin >> user_login_action;
	loginpageactionhandler(user_name,user_login_action);
	return 0;
}