#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <windows.h>
#include "main.h"
#include "loginpage.h"
//while (std::getline(myFile, pfetch)) {
			//std::vector<fiok> bankfiokok = {};
			//bankfiokok.push_back(new fiok(password));
		//}
//CLASS TEMPLATE
class fiok {
public:
	fiok(std::string _password, int _balance, int _cardnum, int _bankid, std::string _t_regis, std::string _rName) {
		rName = _rName;
		password = _password;
		bankid = _bankid;
		cardnum = _cardnum;
		balance = _balance;
		t_regis = _t_regis;
	}
	std::string password; //pass
	std::string rName;
	int balance; //bal
	int cardnum; //card num
	int bankid; //back identi
	std::string t_regis; //time of registration

};
int login() {
	system("CLS");
	std::string user_name;
	std::cout << "[Login]\n";
	std::cout << "Enter your username!\n|Enter 'Exit' to go back to the main page|\n";
	std::getline(std::cin >> std::ws, user_name);
	if (user_name == "Exit") {
		system("CLS");
		main();
	}
	//OPEN FILE? ELSE THROW DOESNT EXIST (mi a fasz)
	std::fstream myFile(user_name, std::ios::in | std::ios::out);
	if (myFile.is_open()) {
		std::cout << "Enter your password!\n";
		std::string password;
		std::getline(std::cin >> std::ws, password);
		std::vector <std::string> pfetch;
		for (size_t i = 0; i < 2; i++)
		{
			std::string pVEC;
			std::getline(myFile, pVEC);
			pfetch.push_back(pVEC);
		}
		if (pfetch[1] == password) {
			system("CLS");
			loginpage(user_name);
		}
		else {
			std::cout << "Invalid password!";
			Sleep(3000);
			system("CLS");
			login();
		}
	}
	else //assuming file isnt open lmfao but who tf knows these days
	{
		std::cout << "User does not exist. Check if you have entered it right.";
		Sleep(3000);
		system("CLS");
		login();
	}
	return 0;
}