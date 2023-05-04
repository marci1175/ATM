#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <string>
#include "loginpage.h"
#include "historycompiler.h"
//i can literally use the same exact variables to withdraw / deposit lmfao

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
int withdraw(std::string user_name) {

		int depositamount;	system("CLS");
		std::cout << "Select from one of the pre-set amounts : \n";
		std::cout << "	        |1. 5|";
		std::cout << "\n	|2. 10		3. 20 |\n	|4. 50		5. 100|\n	|6. 200		7.500 |\n	|8. 1000	9.5000|\n	  |10. Custom amount|\n[To cancel the deposition press 0]\n\n|:";
		int setdepoam;
		std::cin >> setdepoam;
		switch (setdepoam)
		{
		case 0:
			depositamount = 0;
			system("CLS");
			withdraw(user_name);
			break;
		case 1:
			depositamount = 5;
			break;
		case 2:
			depositamount = 10;
			break;
		case 3:
			depositamount = 20;
			break;
		case 4:
			depositamount = 50;
			break;
		case 5:
			depositamount = 100;
			break;
		case 6:
			depositamount = 200;
			break;
		case 7:
			depositamount = 500;
			break;
		case 8:
			depositamount = 1000;
			break;
		case 9:
			depositamount = 5000;
			break;
		case 10:
			std::cout << "Enter the amount of money you want to deposit : ";
			std::cin >> depositamount;
			if (depositamount < 0 or depositamount == 2147483647) {
				std::cout << "Enter a vaild amount of money!";
				Sleep(3000);
				system("CLS");
				withdraw(user_name);
				break;
			}
			break;
		default:
			system("CLS");
			std::cout << "[Select an option listed below!]";
			Sleep(3000);
			withdraw(user_name);
			break;
		}

		//rName
		//password
		//bankid
		//cardnum
		//balance
		//t_regis

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
		veglegesosszeg = balance - depositamount; //this gets sent back
		if (veglegesosszeg < 0) {
			std::cout << "Withdraw cannot continue, you have tried to withdraw too much money.";
			Sleep(3000);
			system("CLS");
			loginpage(user_name);

		}
		regtime = file_vector[5];


		std::vector <fiok> bankfiokok = {};

		// bekérsz minden adatot
		bankfiokok.push_back(fiok(real_name, passwo, bank_id, card_id, veglegesosszeg, regtime));
		myFile.open(user_name, std::ios::out);
		for (const auto& fiokObj : bankfiokok) {
			myFile << real_name << std::endl << passwo << std::endl << bank_id << std::endl << card_id << std::endl << veglegesosszeg << std::endl << regtime << std::endl;
		}
		myFile.flush();
		myFile.close();
		//std::string user_name ,std::string recpnam,int balance,int veglegesosszeg, int depositamount, int sendam, int sveglegesosszeg, int sbalance
		historycompiler(user_name,user_name, balance, veglegesosszeg, depositamount,0,0,0);
		return 0;
	}
	//3000
	//2k
	//	2000 1k
	//	3000 2k
	//	1000 1k
//	std::cout << "1." << veglegesosszeg; //0
//	std::cout << "2." << balance; //5000
//
//	std::cout << "3." << depositamount; //5000