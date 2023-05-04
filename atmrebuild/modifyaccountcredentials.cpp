#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <cstring>
#include "loginpage.h"
#include "namemod.h"
class fiok {
public:
	fiok(std::string _rName, std::string _password, int _bankid, int _cardnum, int _veglegesosszeg, std::string _registime) {
		rName = _rName;
		password = _password;
		bankid = _bankid;
		cardnum = _cardnum;
		veglegesosszeg = _veglegesosszeg;
		registime = _registime;
	}
	std::string password; //pass
	std::string rName;
	int veglegesosszeg; //bal
	int cardnum; //card num
	int bankid; //back identi
	std::string registime; //time of registration
};
int modifyaccountcredentials(std::string user_name) {
	system("CLS");


	std::fstream myFile;
	myFile.open(user_name, std::ios::in | std::ios::out);
	std::string file_tartalom;
	std::vector <std::string> file_vector;
	while (std::getline(myFile, file_tartalom)) {
		file_vector.push_back(file_tartalom);
	}
	myFile.flush();
	myFile.close();
	//file_vector[0] => Igazi név
	//file_vector[1] => Jelszó
	//file_vector[2] => bank id
	//file_vector[3] => bankkártya id
	//file_vector[4] => Balance
	//file_vector[5] => regisztrációs idõpont

	//Start modifying the vectors, converting them ill could modify the vaules rn but i want to flex with my knowledge [Big brain wojak]
	//std::string _password, int _balance, int _cardnum, int _bankid, std::string _t_regis, std::string _rName
	std::string real_name; std::string passwo; std::string regtime;
	int bank_id; int card_id; int balance; int veglegesosszeg;

	real_name = file_vector[0];
	passwo = file_vector[1];
	bank_id = stoi(file_vector[2]);
	card_id = stoi(file_vector[3]);
	balance = stoi(file_vector[4]);
	veglegesosszeg = balance; //this gets sent back
	regtime = file_vector[5];




	int acc;
	std::cout << "Which credential do you want to modify?\n1)Account owner name \n2)Username \n3)Password \n";
	//std::getline(std::cin >> std::ws, [var]);
	std::string newinf1,newinf3,newinf;
	std::cin >> acc;
	std::string mpasswo;
	switch (acc)
	{
	case 0:
		system("CLS");
		loginpage(user_name);
		break;
	case 1:
		std::cout << "Enter your new name : ";
		std::getline(std::cin >> std::ws, newinf1);
		file_vector[0] = newinf1;
		real_name = file_vector[0];
		system("CLS");
		break;
	case 2:
		namemod(user_name);
	case 3:
		std::cout << "Enter your new password : ";
		std::getline(std::cin >> std::ws, newinf3);
		file_vector[1] = newinf3;
		passwo = newinf3;
		system("CLS");
		break;
	default:
		system("CLS");
		std::cout << "Choose a vaild number!";
		Sleep(3000);
		modifyaccountcredentials(user_name);
		break;
	}
	std::vector <fiok> bankfiokok = {};
	// bekérsz minden adatot
	bankfiokok.push_back(fiok(real_name, passwo, bank_id, card_id, veglegesosszeg, regtime));
	myFile.open(user_name, std::ios::out);
	for (const auto& fiok : bankfiokok) {
		myFile << real_name << std::endl << passwo << std::endl << bank_id << std::endl << card_id << std::endl << veglegesosszeg << std::endl << regtime << std::endl;
	}
	myFile.flush();
	myFile.close();
	return 0;
}