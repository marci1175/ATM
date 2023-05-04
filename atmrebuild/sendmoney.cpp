#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#include "loginpage.h"
#include "historycompiler.h"

class fiok {
public:
	fiok(std::string _rName, std::string _password, int _bankid, int _cardnum, int _veglegesosszeg, std::string _regtime) {
		rName = _rName;
		password = _password;
		bankid = _bankid;
		cardnum = _cardnum;
		veglegesosszeg = _veglegesosszeg;
		regtime = _regtime;
	}
	std::string password; //pass
	std::string rName;
	int veglegesosszeg; //bal
	int cardnum; //card num
	int bankid; //back identi
	std::string regtime; //time of registration

};
int sendmoney(std::string user_name) {
	std::fstream myFile;
	std::string recpnam;
	std::cout << "Enter the recpients name : ";
	std::getline(std::cin >> std::ws, recpnam);

	myFile.open(recpnam, std::ios::in | std::ios::out);
	if (!myFile.is_open()) {
		std::cout << "User not found!";
		system("CLS");
		loginpage(user_name);
	}
	else {
		myFile.flush();
		myFile.close();
	}
	int sendam;
	std::cout << "Enter the amount of money you want to send : ";
	std::cin >> sendam;
	//REOPEN AT SENDER
	myFile.open(user_name, std::ios::in | std::ios::out);
	std::string sfile_tartalom;
	std::vector <std::string> sfile_vector;
	while (std::getline(myFile, sfile_tartalom)) {
		sfile_vector.push_back(sfile_tartalom);
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
	std::string sreal_name; std::string spasswo; std::string sregtime;
	int sbank_id; int scard_id; int sbalance; int sveglegesosszeg;

	sreal_name = sfile_vector[0];
	spasswo = sfile_vector[1];
	sbank_id = stoi(sfile_vector[2]);
	scard_id = stoi(sfile_vector[3]);
	sbalance = stoi(sfile_vector[4]);
	sveglegesosszeg = sbalance - sendam;
	if (sveglegesosszeg < 0 or sendam < 0) {
		std::cout << "Transfer cannot continue, you have tried to send too much money or you have tried to send a negative amount.";
		Sleep(3000);
		system("CLS");
		loginpage(user_name);
		
	}
	sregtime = sfile_vector[5];


	std::vector <fiok> sbankfiokok = {};

	sbankfiokok.push_back(fiok(sreal_name, spasswo, sbank_id, scard_id, sveglegesosszeg, sregtime));
	myFile.open(user_name, std::ios::out);
	for (const auto& fiokObj : sbankfiokok) {
		myFile << sreal_name << std::endl << spasswo << std::endl << sbank_id << std::endl << scard_id << std::endl << sveglegesosszeg << std::endl << sregtime << std::endl;
	}
	myFile.flush();
	myFile.close();
	//std::string user_name ,int balance,int veglegesosszeg, int depositamount, int sendam, int sveglegesosszeg, int sbalance
	historycompiler(user_name, user_name, 0, 0, 0, sendam, sveglegesosszeg, sbalance);
	//reopen at recipient


	myFile.open(recpnam, std::ios::in | std::ios::out);
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
	regtime = file_vector[5];
	balance = stoi(file_vector[4]);
	//	sveglegesosszeg = sbalance - sendam;
	veglegesosszeg = balance + sendam; //this gets sent back

	//rewrite all of the info to the file
	std::vector <fiok> bankfiokok = {};

	bankfiokok.push_back(fiok(real_name, passwo, bank_id, card_id, veglegesosszeg, regtime));
	myFile.open(recpnam, std::ios::out);
	for (const auto& fiokObj : bankfiokok) {
		myFile << real_name << std::endl << passwo << std::endl << bank_id << std::endl << card_id << std::endl << veglegesosszeg << std::endl << regtime << std::endl;
		historycompiler(user_name, recpnam, balance, veglegesosszeg, sendam, 0, 0, 0);
	}
	myFile.flush();
	myFile.close();
	//the history compiler will only work with the recepient, since the variables are configed that way :C
	//ill have to fix so itll work with both subjects
	//construct sveglegesosszeg = sbalance - sendam;
	//std::string user_name ,int balance,int veglegesosszeg, int depositamount, int sendam, int sveglegesosszeg, int sbalance
	
	//Minus 
	return 0;
}