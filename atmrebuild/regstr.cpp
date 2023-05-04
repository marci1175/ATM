#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <windows.h>
#include "main.h"
#pragma warning(disable : 4996)
//CLASSES [MÉG TÖBB SZOPÁS EZAZ]
//rName
//password
//bankid
//cardnum
//balance
//t_regis
class fiok {
public:
	fiok() = default;
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


//REGSTR()
int regstr() {
	system("CLS");
	//info lekérés
	std::string user_name;
	std::string password;
	std::string rName;
	std::cout << "[Register]";
	std::cout << "\nEnter a Username!\n|Enter 'Exit' to go back to the main page|\n";
	std::getline(std::cin >> std::ws, user_name);
	if (user_name == "Exit") {
		system("CLS");
		main();
	}


	//check if user already exists
	std::fstream myFile;
	myFile.open(user_name, std::ios::in);
	if (myFile.is_open()) {
		std::cout << "User already exists!\n";
		Sleep(3000);
		system("CLS");
		regstr();
	}
	myFile.flush();
	myFile.close();
	//close file


	std::cout << "\nEnter a password!\n[AVOID THE USE OF SPECIAL CHARACTERS!]\n";
	std::getline(std::cin >> std::ws, password);
	std::cout << "\nEnter your full name!\n[AVOID THE USE OF SPECIAL CHARACTERS!]\n";
	std::getline(std::cin >> std::ws, rName);
	//objektum note ANÁLIZÁLD CSET GPT!!!!
	fiok myObj;

	// Access attributes and set values



	//rName
	//password
	//bankid
	//cardnum
	//balance
	//t_regis

	//time gen
	time_t now = time(0);
	tm* gmtm = gmtime(&now);

	//id gen
	std::default_random_engine rng(std::random_device{}()); // Make the random number generator
	std::uniform_int_distribution<int> dist(1, 900000000); // Define the range of numbers you want to make
	int bankid = dist(rng); // Generate a number

	myObj.rName = rName;
	myObj.password = password;
	myObj.bankid = bankid;
	
	int cardnum = dist(rng); // Generate a number
	
	myObj.cardnum = cardnum;
	myObj.balance = 0;
	myObj.t_regis = asctime(gmtm);

	//file writing
	myFile.open(user_name, std::ios::out);
	if (myFile.is_open()) {

		myFile << myObj.rName << std::endl;
		myFile << myObj.password << std::endl;
		myFile << myObj.bankid << std::endl;
		myFile << myObj.cardnum << std::endl;
		myFile << myObj.balance << std::endl;
		myFile << myObj.t_regis << std::endl;

		myFile.flush();
		myFile.close();
	}
	else {
		std::cout << "Error occured";
	}
	//create the history file
	myFile.open(user_name + "history", std::ios::in);
	//created file
	myFile.close();
	myFile.flush();


	system("CLS");
	std::cout << "-- Successfully registered, as " << user_name << " ! --\n" << std::endl;
	return 0;
}